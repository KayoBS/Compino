# COMPINO
This is a small (really small) library for compiling and sending code to Arduino. Currently, it meets all my needs by doing only the very basics, so much so that the code is quite poor, but I intend to improve it and add other functionalities in the future.
## Requirements
You need to have ```arduino-cli``` installed.
## Initial Steps
First, compile the code with ```make``` and, to make the compiled code a command, use ```make install```.
To clear intermediate files, use ```make clean``` and to uninstall the command, use ```make uninstall```.
## How to Use
To open the help tab, type ```compino --help``` or ```compino -h```.

To compile your .ino code for your board, first make sure it is connected and, to be sure which serial port you should use to send the code, use the command ```arduino-cli board list```. Knowing which port to use, type ```compino your_serial_port```, where "your_serial_port" is the port where the Arduino Uno is connected.
Example: ```compino /dev/ttyUSB0```
