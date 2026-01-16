# COMPINO
This is a small command-line tool designed to simplify compiling and uploading to Arduino board family, specificaly for older or low-spec computers. Currently, it meets all my needs by providing the essential basics.

## My Setup
I am currently using a 2016 Lenovo Ideapad 110 with 3.73 GB of RAM, an Intel Celeron N3060 processor (2.48 GHz), integrated graphics, and running Arch Linux with i3WM.

## Requirements
* ```arduino-cli``` installed.
* ```make``` intalled.
* Any Linux distribution.

## Installation

```bash
git clone https://github.com/kayobs/compino
cd compino/
make install
make clean
```

 Installation commands:
* To compile and install the tool: ```make install```
* To remove intermediate files: ```make clean```
* To unistall: ```make uninstall```

## How to Use
* Display the help guide and examples: ```compino -h```
* Check version: ```compino -v```

#### Compiling and Uploading
1. Ensure your board is connected.
2. Identify the serial port using: ```arduino-cli board list```
3. Run Compino: ```compino -s serial_port -b board_name```

> Examples

```bash
compino -s /dev/ttyACM0 -b uno
compino -b mega -s /dev/ttyUSB0
```

#### Simplified Board Naming
You don't need to type the full FQBN (Fully Qualified Board Name). Compino recognizes short aliases:
* Use ```uno``` for Arduino Uno.
* Use ```mega``` for Arduino Mega.
* Use ```nano``` for Arduino Nano.
* Use ```micro``` for Arduino Micro.
* Use ```leo``` for Arduino Leonardo.

## Future Features
- **Visual Feedback:** Colorized output messages to distinguish between success, warnings and errors.
- **Simplified Error Messages:** More direct error messages with more refined error handling.
- **New Commands:** Additional commands while maintaining the project's simplicity.
- **Auto-detection:** Automatically detect the serial port if only one device is connected.
- **Project Config:** Support for local config file to save default board settings per folder.
