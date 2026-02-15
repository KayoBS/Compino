#include <iostream>
#include <string>
#include <vector>

#include "src/print_help_guide.hpp"

// Revisar o problema no envio de código para o Arduino Nano

// compile .ino | compile for arduino
int main(int argc, char *argv[]) {

  std::vector<std::string> command_args(argv + 1, argv + argc);

  if( argc < 2 || argc >= 8 ) {
    std::cout << "Invalid number of arguments! To see how this command works, type: compino -h" << '\n';
  }
  else {

    std::string compile_command = {""};
    std::string upload_command = {""};

    std::string board = {""};
    std::string serial_port = {""};

    std::string board_type = {"arduino:avr:"}; //Usar isso para o arquivo de configuração padrão depois

    unsigned char uc_flag = {0b00000000}; //Upload-Compile Flag
    bool compile_try = {false};


    //Depois tentar implementar um foreach ou uma recursão!
    for( size_t cont = 0 ; cont < command_args.size() ; ++cont ) {

      std::string* arg = &command_args[cont];

      if(*arg == "-h") {
        //Depois mudar isso para um system(cat ~/etc/bin/helpguide.txt)
        print_help_guide();
      }

      else if(*arg == "-v") {
        std::cout << "1.4.1  -  2026.02.15" << '\n';
      }

      else if(*arg == "-l") {
        system("arduino-cli board list");
      }

      else if(*arg == "-b") {
        if( (cont+1) < command_args.size() ) {
          board = command_args[++cont];
          uc_flag |= 0b11110000;
          compile_try = true;
        }
        else {
          std::cout << "You need to specify the Arduino model after the -b flag! For more information and examples, type: compino -h" << '\n';
        }
      }

      else if(*arg == "-s") {
        if( (cont+1) < command_args.size() ) {
          serial_port = command_args[++cont];
          uc_flag |= 0b00001111;
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
      uc_flag &= 0b11111111;
      compile_command = "arduino-cli compile --fqbn " + board_type + board + " .";
      upload_command = "arduino-cli upload -p " + serial_port + " --fqbn " + board_type + board + " .";

      if( uc_flag == 0b11111111 ) {
   
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
