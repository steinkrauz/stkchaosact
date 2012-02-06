/*
 Chaos Act -- automated Chaos ritual

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



int main(int argv, char *argc[]){
  int ChaosBufLength,i, TotalCount;
  char *ChaosBuf;
  FILE *input, *ChaosGate;

  srand(time(NULL)); /* seeding CHAOS in the first place */
  
  input = stdin;
  TotalCount = 0;
  
  while(!feof(input)){
     ChaosBufLength = (rand()%1008)+16;  /* Chunks size from 16 to 1024 bytes */
     ChaosBuf = (char *)malloc(ChaosBufLength);
     fgets(ChaosBuf,ChaosBufLength,input);
     i = 0;
     while(ChaosBuf[i]!='\0') {    /* Mixing in the CHAOS component */
       ChaosBuf[i] = ChaosBuf[i]^(rand()%256);
       i++;
     }
     TotalCount += i;
     if ((ChaosGate=fopen("/dev/null","wt"))==NULL){ /*Opening the gates to chaos*/
	     perror("Gates won't open for you!"); return 11;
     }
     fwrite(ChaosBuf,ChaosBufLength,1,ChaosGate);  /* Dumping the victim into the Gates */
     fclose(ChaosGate); /* Close the Gates */
     free(ChaosBuf); /* Scatter the ashes */
  }
  printf("%d bytes were devoured by CHAOS\n",TotalCount);
  return 0;
}
