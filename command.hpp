#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <iostream>

/*
 * something, something, command
 */

class Command
{
  private:
    std::string cmd_str;
    std::string help_str;
    void (*callback) (std::string &s);

  public:
    Command();

    Command( 
        const char *, 
        void(*callback_fun)(std::string &s) );

    Command( 
        const char *, 
        const char *, 
        void(*callback_fun)(std::string &s) );

    void set( 
        const char *, 
        void(*callback_fun)(std::string &s) );

    int mulch(std::vector<char> &);
    int mulchHelp(std::vector<char> &);
    void printHelp();
};


#endif
