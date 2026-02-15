#include "print_help_guide.hpp"

void print_help_guide() {
  std::cout << "This is the compino help guide, a command-line tool designed to simplify compiling and uploading to Arduino board family on older or low-spec computers." << '\n';
  std::cout << "-h                        - Help guide" << '\n';
  std::cout << "-v                        - Version" << '\n';
  std::cout << "-l                        - List connected boards and available serial ports" << '\n';
  std::cout << "-s <serial port>          - Indicates which serial port the code should be compiled for (serial port where the Arduino is connected)" << '\n';
  std::cout << "-b <board name>           - Indicates which Arduino family model to compile for" << '\n';

  std::cout << "\nExample usage format:" << '\n';
  std::cout << "compino -s /dev/ttyUSB0 -b uno" << '\n';
}
