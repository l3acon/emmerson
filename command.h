#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

/*
 * class of commands
 * yay
 */

class Command
{
  private:
    std::string match;
    void (*callback) (std::string &s);

  public:
    Command();
    Command( const char *match_str, void(*callback_fun)(std::string &s) );

    int mulch(std::vector<char> &buff );
};


#endif
