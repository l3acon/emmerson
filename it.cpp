/*
 * todo: <describe me>
 *
 * Copyleft l3acon at gmail dot com 2015
 *   Your use of this thing implies you agree to each of these terms:
 *     (1) This thing is always free to use, copy, modify, and distribute.
 *     (2) This thing is provided "as is" without warranty of any kind.
 *      If anything goes awry you assume all responsibility and cost.
 *     (3) You buy me a beer if we meet.
 *
 */

#include <iostream>
// printf is nice
#include <cstdio>   
// no cpp signal handling plz
#include <signal.h> 
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

//ma stuff
#include "colors.h"
#include "cmds.h"

#define BUFFLEN 180
#define IPRINT(x) printf(x); fflush(stdout);

void getInput( std::vector<char> &buff);
void ignoreSigint( int ignore);

inline void prompt()
{
  printf("# %semmers0n %s%%%s ", KGRN, KYEL, KWHT);
  fflush(stdout);
  //IPRINT("# emmers0n %% ");
}

void noCmd(std::vector<char> buff)
{
  IPRINT(" command \"");
  for(int i=0; i<buff.size()-1; ++i)
    putchar(buff[i]);
  IPRINT("\" not found\ntype \"help\" for help on commands\n");
}

int main(void)
{
  if (signal(SIGINT, ignoreSigint) == SIG_ERR)
    printf("[FAILED] to install SIGINT handle\n");

  Cmds avaliable_cmds;
  avaliable_cmds.init();
  std::vector<char> buff;
  try
  {
    while(true)
    {
      buff.clear();
      getInput( buff );
      avaliable_cmds.mulchAll( buff );
    }
  }
  catch(std::exception& e)
  {
    return 0;
  }
  return 0;
}

void getInput(std::vector<char> &buff)
{
  prompt();
  do
    buff.push_back( getc(stdin) );
  while( buff.back() != '\n' );
}

void ignoreSigint( int ignore)
{
  printf("\n# %semmers0n %s%%%s ", KGRN, KYEL, KWHT);
  //IPRINT("\n# emmers0n %% ");
  fflush(stdout);
  return;
}

