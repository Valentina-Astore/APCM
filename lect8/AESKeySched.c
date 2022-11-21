#include <stdio.h>
#include <inttypes.h>
#include "AES.Lib.h"


int main(){
  int i,j,k;
  // Chiave di partenza
  uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]=
    {{0x2b,0x7e,0x15,0x16}, // I   colonna
     {0x28,0xae,0xd2,0xa6}, // II  colonna
     {0xab,0xf7,0x15,0x88}, // III colonna
     {0x09,0xcf,0x4f,0x3c}};// IV  colonna

  // Le roundkey contengono la chiave di partenza
  uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD];
  roundKeyGen(roundKey,Key);
  //

  // Stampo le chiavi come nello schema
  printf("Round Keys generated.\n\n");
  for(i=0;i<=NR_ROUNDS;i++) {
    printf("Round key %d\n", i);
    for(k=0;k<BYTES_IN_WORD;k++){
      for(j=0;j<WORDS_IN_KEY;j++){

	printf("%02X ", roundKey[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }



}


