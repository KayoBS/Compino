#include "exec.hpp"

void Exec::compilation( std::string *board ) {
  std::string compile_command = "arduino-cli compile --fqbn " + board_type + *board + " .";

  system( compile_command.c_str() );
}
