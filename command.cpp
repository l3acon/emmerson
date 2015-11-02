#include "command.h"

/*
 * @param input vector (my favourite string type)
 * @return number of matches successful
 */


Command::Command()
{
  ;
}

Command::Command( const char *match_str, void(*callback_fun)(std::string &s) ) : match( match_str)
{
  callback = callback_fun;
}

int Command::mulch( std::vector<char> &buff )
{
  std::string in( buff.data() );
  std::size_t found = in.find(match);
  if( found != std::string::npos )
  {
    std::string sub( in.substr(found, in.size() ) );
    callback( sub );
    return 1;
  }
  return 0;
}


