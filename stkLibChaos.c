/*
Chaotic functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "stkLibChaos.h"

ChaoticChunk * summonChaoticBuffer(){
   ChaoticChunk *newChunk;
   newChunk = (ChaoticChunk *)malloc(sizeof(ChaoticChunk));
   newChunk->size = (rand()%(CHAOS_CHUNK_MAX - CHAOS_CHUNK_MIN ))+CHAOS_CHUNK_MIN;
   newChunk->bytes = (char *)malloc(newChunk->size);
   return newChunk;
}

void disperseChaoticBuffer(ChaoticChunk *chunk){
   free(chunk->bytes);
   free(chunk);
}
/* Mixing in CHAOS component */
size_t chaoticCorruption(ChaoticChunk *chunk){
   size_t i = 0;
   while(i<chunk->size && chunk->bytes[i]!='\0'){
     chunk->bytes[i] = chunk->bytes[i]^(rand()%256);
     i++;
   }
   return i;
}

void eructateInChaos(ChaoticChunk *chunk){
   FILE *ChaosGate;
   if ((ChaosGate=fopen("/dev/null","wt"))==NULL){ /*Opening the gates to chaos*/
	     perror("Gates won't open for you!"); exit(11);
     }
   fwrite(chunk->bytes,chunk->size,1,ChaosGate);  /* Dumping the victim into the Gates */
   fclose(ChaosGate); /* Close the Gates */
}

void chaoticPrint(char *format, ...) {
  char buffer[PRINT_BUFFER_SIZE];
  va_list args;
  size_t length, p;
  int i,traits_num;

  va_start (args, format);
  vsprintf (buffer,format, args);
  length = strlen(buffer);
  traits_num = (length * CHAOS_TRAITS_PERCENT) / 100;
  /* leaving chaos traits on the message */
  for (i=0;i<traits_num;i++){
     p = rand()%length;
     buffer[p] = buffer[p]^(rand()%256);
  }
  puts (buffer);
  va_end (args);
}
