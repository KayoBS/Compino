#include <iostream>
#include <string>

// compile .ino | compile for arduino
int main(int argc, char *argv[]) {

  if (argc == 2) {
    std::string port = argv[1];
    std::string port_command = port;

    if (port_command == "--help" || port_command == "-h") {

      std::cout << "To compile your .ino file, type \"compino your_serial_port\", where \"your_serial_port\" is the port to which your Arduino Uno is connected.To see the connected ports, use the command \"arduino-cli board list\"";
      std::cout << "\n\n--help       -h    - help guide";
    }

    else {
      port_command =
          "arduino-cli upload -p " + port + " --fqbn arduino:avr:uno .";

      std::cout << "\nCommand port defined";

      std::system("arduino-cli compile --fqbn arduino:avr:uno .");
      std::cout << "\nCompilation ends";

      std::system(port_command.c_str());
      std::cout << "\nCode uploaded to serial port " << port;
    }
  }

  else {
    std::cout << "\nInvalid number of arguments";
  }

  std::cout << '\n';

  return 0;
}
