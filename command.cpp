#include "command.hpp"

/*
 * @param input vector (my favourite string type)
 * @return number of matches successful
 */

Command::Command()
{
  ;
}

Command::Command( 
    const char *_match_str, 
    void(* _callback_fun)(std::string &s) 
    ) : cmd_str( _match_str)
{
  callback = _callback_fun;
}

Command::Command( 
    const char *_match_str, 
    const char *_help_str, 
    void(*_callback_fun)(std::string &s) 
    ) : cmd_str( _match_str), help_str(_help_str) 
{
  callback = _callback_fun;
}

void Command::printHelp()
{
  std::cout << help_str << std::endl;
  fflush(stdout);
}

void Command::set( const char *_match_str, void(* _callback_fun)(std::string &s) )
{
  callback = _callback_fun;
  cmd_str.clear();
  cmd_str = std::string(_match_str);
}

int Command::mulch( std::vector<char> &buff )
{
  if( mulchHelp( buff ) != 0 )
    return -1;

  std::string in( buff.data() );
  std::size_t found = in.find(cmd_str);
  if( found != std::string::npos )
  {
    std::string sub( in.substr(found, in.size() ) );
    callback( sub );
    return 1;
  }
  // if it isn't found look for help
  return 0;
}

int Command::mulchHelp( std::vector<char> &buff )
{
  std::string in( buff.data() );
  std::size_t found = in.find(cmd_str);
  if( found != std::string::npos )
  {
    std::string sub( in.substr(found, in.size() ) );
    printHelp();
    return 1;
  }
  return 0;
}

