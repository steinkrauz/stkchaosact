/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */ 

/*
 Chaos Act -- automated Chaos ritual

You should recite this incantation before running make in order to get the sofware to work properly.

Cunning canines
Galloping Gorgones
Violent vipers
Push thy powers through
Cold numbers of the silent silicon
To devour, destroy, devastate!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "stkLibChaos.h"

#define MAX_FORKS 16

int main(int argv, char *argc[]){
  int TotalCount, ForkCount;
  ChaoticChunk *ChaoticBuffer;
  FILE *input;
  pid_t pid;

  srand(time(NULL)); /* seeding CHAOS in the first place */
  
  input = stdin;
  TotalCount = 0;

  
  while(!feof(input)){
     ChaoticBuffer = summonChaoticBuffer();
     fgets(ChaoticBuffer->bytes,ChaoticBuffer->size,input);
     TotalCount += chaoticCorruption(ChaoticBuffer);
     ForkCount = rand()%MAX_FORKS;
     while(ForkCount-->0&&pid>0) pid = fork();/* will destroy it simultaneously */
     eructateInChaos(ChaoticBuffer);
     disperseChaoticBuffer(ChaoticBuffer); /* Scatter the ashes */
     if (pid==0) break;
  }
  if (pid>0)
     chaoticPrint("%d bytes were devoured by CHAOS\n",TotalCount);
  return 0;
}
