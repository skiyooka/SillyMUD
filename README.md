# VerySillyMUD
A refactoring exercise based on SillyMUD, a derivative of DikuMUD.

Modified to run on an Espressif devit.

# Linux / MacOS
## Building

```
$ cd main
$ make
```

## Running the game

Within the main folder after building:
```
$ ./sillymud -d ../lib
```

The major note is that the first player to log in will become an
"Implementor" level god; after the first log in, that player will need
to have an entry in the [`security`](lib/security/) directory. See the [`README`](lib/security/README) file in
that directory for more details.


Further documentation for running the game is found in [`running.doc`](doc/running.doc).

# Espressif

## Create and flash the FAT filesystem image

All of the world files (within the `lib` folder) must first be put into a FAT filesystem image and then flashed to the Espressif devkit.

The image size is 4 MB in order to store everything and have some space for player files etc.

```
$ source /PATH/TO/esp-idf/export.sh
$ /PATH/TO/esp-idf/components/fatfs/wl_fatfsgen.py --partition_size 0x400000 --sector_size 4096 --long_name_support --output_file fat.image lib
```

Then flash the FAT filesystem image to the devkit. Note that the parameters may differ on your system depending on the type of devkit and which port it is connected. The destination address depends on the partition table.
```
$ esptool.py --chip esp32c6 --port /dev/cu.usbserial-110 --baud 115200 write_flash 0x00210000 fat.image
```

## Building and Flashing

Build and tested using ESP-IDF v5.5

```
$ idf.py build
$ idf.py flash
$ idf.py monitor
```

## Running the game

The MUD will start automatically. Connect using telnet to port 4000.
