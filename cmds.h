#ifndef CMDS_H
#define CMDS_H

#include <string>
#include <vector>

#include "command.hpp"

/*
 * class for commands yay!
 */

class Cmds
{
  public:
    void init();
    int mulchAll( std::vector<char> &buff );
    int mulchHelp( std::vector<char> &buff );
    void printAllHelp();
    void printHelp( Command &command);
    std::vector<std::string> & tokenize( std::vector<char> &str, char c);

  private:
    std::vector<Command> commands;
};

#endif
