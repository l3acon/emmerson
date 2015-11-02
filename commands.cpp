#include "commands.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef IPRINT
#define IPRINT(x) printf(x); fflush(stdout);
#endif

void routeExit( std::string &s)
{
  IPRINT("goodbye\n"); 
  exit(0); 
}

static void routeHelp( std::string &s)
{
  IPRINT("This is the help menu:\n\tsomething\n\tsomething\n\tsomething\n"); 
}

static void routeLs( std::string &s )
{
  IPRINT("diary.txt\tathing.bff\nsomethingelse.m\nanothertning.xyz\n"); 
}

void Commands::init() 
{
  cmds.push_back( Command("exit", routeExit) ) ;
  cmds.push_back( Command("help", routeHelp) ) ;
  cmds.push_back( Command("ls", routeLs) ) ;
}

int Commands::mulch_all( std::vector<char> &buff )
{
  int acc = 0;
  for( std::vector<Command>::iterator it = cmds.begin();
    it != cmds.end();
    ++it)
    {
      acc += it -> mulch( buff );
    }
  return acc;
}

//extern Commands cmds;
