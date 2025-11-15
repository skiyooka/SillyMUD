/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <stdlib.h> // exit, atoi
#include <unistd.h> // read, write, close

#include <socket.h>

#include <string.h> // memset

#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_console.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "nvs.h"
#include "nvs_flash.h"

// FATFS
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include <dirent.h>

#include "memfault/esp_port/core.h"
#include "memfault/components.h"


static void print_system_info() {
    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());
}


static void initialize_nvs() {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
}


bool wifi_join(const char *ssid, const char *pass);

void register_system();
#define PROMPT_STR CONFIG_IDF_TARGET
#define CONFIG_CONSOLE_MAX_COMMAND_LINE_LENGTH 80


static const char *TAG = "FAT";
// Handle of the wear levelling library instance
static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;
// Mount path for the partition
const char *base_path = "";  // this cannot be "/"

void fat_initialize() {
    // Setup FAT file system
    ESP_LOGI(TAG, "Mounting FAT filesystem");
    const esp_vfs_fat_mount_config_t mount_config = {
        .max_files = 16,
        .format_if_mount_failed = true,
        .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount_rw_wl(base_path, "storage", &mount_config, &s_wl_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount FATFS (%s)", esp_err_to_name(err));
        return;
    }

    // Write file
    ESP_LOGI(TAG, "Opening file");
    FILE *f = fopen("hello.txt", "w");
    fprintf(f, "Written using ESP-IDF\n");
    fclose(f);
    ESP_LOGI(TAG, "File written");

    // Read file
    ESP_LOGI(TAG, "Reading file");
    f = fopen("hello.txt", "r");
    char line[64];
    fgets(line, sizeof(line), f);
    fclose(f);

    // Print data
    char *pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Data from file: '%s'", line);

    // List directory
    ESP_LOGI(TAG, "Listing directory:");
    DIR *dir = opendir("/");
    if (dir != NULL) {
        struct dirent *ent;
        while ((ent = readdir(dir)) != NULL) {
            ESP_LOGI(TAG, "  %s", ent->d_name);
        }
        closedir(dir);
    } else {
        ESP_LOGE(TAG, "Failed to open directory");
    }

    // Unmount FATFS
    /*
    ESP_LOGI(TAG, "Unmounting FAT filesystem");
    esp_vfs_fat_spiflash_unmount_rw_wl(base_path, s_wl_handle);
    ESP_LOGI(TAG, "Done");
    */
}

int real_main(int argc, char **argv);


void app_main() {
    printf("Hello world!\n");
    print_system_info();

    memfault_boot();
    memfault_device_info_dump();

    initialize_nvs();
    const char *ssid = "<TODO:SSID>";
    const char *pass = "<TODO:PASS>";

    bool result = wifi_join(ssid, pass);
    if (!result) {
        printf("Failed to join WiFi network\n");
    }


    printf("Registering commands for ESP console...\n");
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    /* Prompt to be printed before each line.
     * This can be customized, made dynamic, etc.
     */
    repl_config.prompt = PROMPT_STR ">";
    repl_config.max_cmdline_length = CONFIG_CONSOLE_MAX_COMMAND_LINE_LENGTH;

    /* Register commands */
    esp_console_register_help_command();
    register_system();

    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_uart(&hw_config, &repl_config, &repl));

    ESP_ERROR_CHECK(esp_console_start_repl(repl));
    printf("Done registering commands for ESP console.\n");

    fat_initialize();

    // real_main(0, NULL); // mud main
}
