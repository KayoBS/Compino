#include "exec.hpp"

void Exec::list() {
  system("arduino-cli board list");
}
