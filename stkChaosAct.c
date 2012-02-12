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
#include "stkLibChaos.h"


int main(int argv, char *argc[]){
  int TotalCount;
  ChaoticChunk *ChaoticBuffer;
  FILE *input;

  srand(time(NULL)); /* seeding CHAOS in the first place */
  
  input = stdin;
  TotalCount = 0;
  
  while(!feof(input)){
     ChaoticBuffer = summonChaoticBuffer();
     fgets(ChaoticBuffer->bytes,ChaoticBuffer->size,input);
     TotalCount += chaoticCorruption(ChaoticBuffer);
     eructateInChaos(ChaoticBuffer);
     disperseChaoticBuffer(ChaoticBuffer); /* Scatter the ashes */
  }
  printf("%d bytes were devoured by CHAOS\n",TotalCount);
  return 0;
}
