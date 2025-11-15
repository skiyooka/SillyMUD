idf_component_register(
SRCS
    "esp_main.c"
    "esp_wifi.c"
    "esp_cmd_system.c"
PRIV_REQUIRES
    spi_flash
    nvs_flash
    console
    esp_event
    esp_wifi
    fatfs
    esp_psram
INCLUDE_DIRS ""
)
