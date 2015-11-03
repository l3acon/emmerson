#include "cmds.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef IPRINT
#define IPRINT(x) printf(x); fflush(stdout);
#endif

void fExit( std::string &s)
{
  IPRINT("goodbye\n"); 
  exit(0); 
}
const char exit_help_str[] =
"This is the print text for exit\n";

static void fLs( std::string &s )
{
  IPRINT("diary.txt\tathing.bff\nsomethingelse.m\nanothertning.xyz\n"); 
}
const char ls_help_str[] =
"This is the print text for ls\n";

static void fHelp( std::string &s)
{
  printf("%s", s.data() );
  IPRINT("type help <command> for more information on commands\n");
}

const char help_help_str[] =
"This is the print text for the help menu\n";

void Cmds::init() 
{
  commands.push_back( Command("exit", exit_help_str, fExit) ) ;
  commands.push_back( Command("help", help_help_str, fHelp) ) ;
  commands.push_back( Command("ls", ls_help_str, fLs) ) ;
}

int Cmds::mulchAll( std::vector<char> &buff )
{
  std::vector<std::string> &t = tokenize( buff, ' ');

  int acc = 0;
  for( std::vector<std::string>::iterator it = t.begin();
    it != t.end();
    ++it)
    {
      ;
      //if( 
      //acc += it -> mulch( buff );
    }
  return acc;
}

std::vector<std::string> & Cmds::tokenize( std::vector<char> &str, char c = ' ')
{
  static std::vector<std::string> result;
  const char *s = str.data();
  do
  {
    const char *begin = s;
    while( *s != c && *s )
      s++;
    result.push_back( std::string(begin, s) );
  } while( *s++ != 0 );

  return result;
}

void Cmds::printAllHelp()
{
  for( std::vector<Command>::iterator it = commands.begin();
      it != commands.end();
      ++it )
    it -> printHelp();
}


