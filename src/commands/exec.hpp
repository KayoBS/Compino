#pragma once
#include <string>
#include "../board_type.hpp"

class Exec {
  private:

  public:
    void print_help_guide();
    void upload( std::string *board, std::string *port );
    void compilation( std::string *board );
    void list();
};
