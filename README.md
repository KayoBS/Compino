# COMPINO
This is a small command to facilitate to compile and send code to Arduino board family in weak/old computers. Currently, it meets all my needs by doing only the very basics.
## The computer I'm using
Currently, I'm using a 2016 Lenovo Ideapad 110 with 3.73 GB of RAM, an Intel Celeron N3060 processor with a 2.48 GHz clock speed, integrated graphics, and running Arch Linux with i3WM as my operating system.
## Requirements
You need to have ```arduino-cli``` installed and any Linux distribution.
## Initial Steps
First, compile and make the compiled code a command with ```make install```.
To clear intermediate files, use ```make clean``` and to uninstall the command, use ```make uninstall```.
## How to Use
To open the help guide for informations and examples, type ```compino -h```.
To check the version, use ```compino -v```

To compile your .ino code for your board, first make sure it is connected and, to be sure which serial port you should use to send the code, use the command ```arduino-cli board list```. Knowing which port to use, type ```compino -s <serial_port> -b <board_name>```, where "serial_port" is the port where the Arduino Uno is connected and "board_name" is the abbreviated name of your board, like "uno", for Arduino Uno, or "mega", for Arduino Mega. For more informations, use the help guide.
Example: ```compino -s /dev/ttyUSB0 -b uno```
## Things to add
I still intend to add colors to the command messages, more sophisticated error messages, and add more commands without compromising the simplicity of this project.

