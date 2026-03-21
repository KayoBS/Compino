#include <iostream>
#include <string>
#include <vector>

#include "src/compino/compino.hpp"

// Revisar o problema no envio de código para o Arduino Nano

// compile .ino | compile for arduino
int main(int argc, char *argv[]) {

  Compino compino;

  std::vector<std::string> command_args(argv + 1, argv + argc);

  if( argc < 2 || argc >= 8 ) {
    std::cout << "Invalid number of arguments! To see how this command works, type: compino -h" << '\n';
  }
  else {

    unsigned char uc_flag = {0b00000000}; //Upload-Compile Flag
    bool compilation_try = {false};

    //Depois tentar implementar um foreach ou uma recursão!
    for( size_t cont = 0 ; cont < command_args.size() ; ++cont ) {

      std::string* arg = &command_args[cont];

      if(*arg == "-h") {
        compino.exec.print_help_guide();
      }

      else if(*arg == "-v") {
        compino.version();
      }

      else if(*arg == "-l") {
        compino.exec.list();
      }

      else if(*arg == "-b") {
        if( (cont+1) < command_args.size() ) {
          compino.board = command_args[++cont];
          uc_flag |= 0b11110000;
          compilation_try = true;
        }
        else {
          std::cout << "You need to specify the Arduino model after the -b flag! For more information and examples, type: compino -h" << '\n';
        }
      }

      else if(*arg == "-s") {
        if( (cont+1) < command_args.size() ) {
          compino.serial_port = command_args[++cont];
          uc_flag |= 0b00001111;
          compilation_try = true;
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


    if( compilation_try ) {
      uc_flag &= 0b11111111;

      if( uc_flag == 0b11111111 ) {
        compino.exec.compilation( &compino.board );
        compino.exec.upload( &compino.board, &compino.serial_port );

      }
      else {
        std::cout << "To be able to compile, you need the serial port and the Arduino model! For more information and examples, type: compino -h" << '\n';
      }
    }
  }
  return 0;
}
