#include <iostream>
#include <bitset>
#include <string>
#include <string_view>
#include <vector>

// compile .ino | compile for arduino
int main(int argc, char *argv[]) {

  std::vector<std::string> command_args(argv + 1, argv + argc);

  std::string compile_command = {""};
  std::string upload_command = {""};

  std::string board = {""};
  std::string serial_port = {""};

  std::bitset<8> in_process = {0b00000000};
  bool compile_try = {false};

  if( argc < 2 || argc >= 8 ) {
    std::cout << "Invalid number of arguments! To see how this command works, type: compino -h" << '\n';
  }
  else {
    //Depois tentar implementar um foreach ou uma recursão!
    for( size_t cont = 0 ; cont < command_args.size() ; ++cont ) {

      std::string_view arg = command_args[cont];

      if(arg == "-h") {
        //Depois mudar isso para um system(cat ~/etc/bin/helpguide.txt)
        std::cout << "This is the compino help guide, a command to facilitate compilation for Arduino family boards on weak/old computers. This command is designed to work on Linux distributions." << '\n';
        std::cout << "-h                        - Help guide" << '\n';
        std::cout << "-v                        - Version" << '\n';
        std::cout << "-s <serial port>          - Indicates which serial port the code should be compiled for (serial port where the Arduino is connected). To see the available ports, use: arduino-cli board list" << '\n';
        std::cout << "-b <board name>           - Indicates which Arduino family model to compile for" << '\n';

        std::cout << "\nExample usage format:" << '\n';
        std::cout << "compino -s /dev/ttyUSB0 -b uno" << '\n';

        std::cout << "\nSupported boards for compilation:" << '\n';
        std::cout << "Arduino Uno         -b uno" << '\n';
        std::cout << "Arduino Mega        -b mega" << '\n';
        std::cout << "Arduino Micro       -b micro" << '\n';
        std::cout << "Arduino Nano        -b nano" << '\n';
        std::cout << "Arduino Leonardo    -b leo" << '\n';
      }

      else if(arg == "-v") {
        std::cout << "2026.01.12" << '\n';
      }

      else if(arg == "-b") {
        if( (cont+1) < command_args.size() ) {
          board = command_args[++cont];
          in_process |= 0b11110000;
          compile_try = true;
        }
        else {
          std::cout << "You need to specify the Arduino model after the -b flag! For more information and examples, type: compino -h" << '\n';
        }
      }

      else if(arg == "-s") {
        if( (cont+1) < command_args.size() ) {
          serial_port = command_args[++cont];
          in_process |= 0b00001111;
          compile_try = true;
        }
        else {
          std::cout << "You need to specify the serial port after the -s flag! For more information and examples, type: compino -h" << '\n';
        }
      }

      else {
        std::cout << "Flag not found: " << command_args[cont] << '\n';
        std::cout << "To see the flags that can be used by this command, access the help guide by typing: compino -h" << '\n';
      }

    }


    if( compile_try ) {
      in_process &= 0b11111111;
      compile_command = "arduino-cli compile --fqbn arduino:avr:" + board + " .";
      upload_command = "arduino-cli upload -p " + serial_port + " --fqbn arduino:avr:" + board + " .";

      if( in_process.all() ) {
   
        //std::cout << "Compiling sketch..." << '\n';
        system( compile_command.c_str() );
        //std::cout << "The sketch has been compiled." << '\n';

        //std::cout << "Sending sketch to the board..." << '\n';
        system( upload_command.c_str() );
        //std::cout << "Sketch successfully sent to the board." << '\n';

      }
      else {
        std::cout << "To be able to compile, you need the serial port and the Arduino model! For more information and examples, type: compino -h" << '\n';
      }
    }
  }
  return 0;
}
