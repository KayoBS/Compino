#include "exec.hpp"

void Exec::upload( std::string *board, std::string *port ) {
  std::string upload_command = "arduino-cli upload -p " + *port + " --fqbn " + board_type + *board + " .";

  system( upload_command.c_str() );
}
