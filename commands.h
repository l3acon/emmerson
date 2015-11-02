#ifndef COMMANDS_H
#define COMMANDS_H

#include "command.h"

class Commands
{
  public:
    void init();
    int mulch_all( std::vector<char> &buff );
  private:
    std::vector<Command> cmds;
};

#endif
