#ifndef STKLIBCHAOS_H
#define STKLIBCHAOS_H
/*
Chaotic header
*/
#include <stddef.h>
/* Chunks size from 16 to 1024 bytes */
#define CHAOS_CHUNK_MAX 1024
#define CHAOS_CHUNK_MIN 16

/* chaoticPrint() configuration */
#define PRINT_BUFFER_SIZE 256
#define CHAOS_TRAITS_PERCENT 15

/* our personal pieces of Chaos */
typedef struct {
   char *bytes;
   size_t size;
} ChaoticChunk;

/* chaotic functions */
ChaoticChunk * summonChaoticBuffer();
void disperseChaoticBuffer(ChaoticChunk *chunk);
size_t chaoticCorruption(ChaoticChunk *chunk);
void eructateInChaos(ChaoticChunk *chunk);
void chaoticPrint(char *format, ...); 

#endif
