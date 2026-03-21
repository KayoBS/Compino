#pragma once
#include "../commands/exec.hpp"


class Compino {
  private:
  public:
    std::string compile_command;
    std::string upload_command;
    std::string board;
    std::string serial_port;

    Exec exec;

    void version();
};
