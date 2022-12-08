#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<inttypes.h>
#include<stdint.h>
#include "PrimeLib.h"
#include "BBSLib.h"
#define MAXBYTES 1000

void print8bit(uint8_t byte){
  int i;
  for (i = 7; i >=0 ; i--) {
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  }
}
 uint8_t Hw(uint8_t word){
  uint8_t Hw=0,bit=word,i;
  
  for (i=0; i<8; i++) {
    if (bit & 1) Hw++;
    bit = (bit >> 1);
  }
  return Hw;
}


int main(int argc, char *argv[]){
  unsigned int r,i;
  unsigned int HammingSum=0;

  uint8_t byte[MAXBYTES];

  if(argc==2){
    r=atoi(argv[1]);
  }  else {
    printf("%s nrbytes \n", argv[0]);
    return 0;
  }

  // Fissa il seed 100, e genera p,q,n,X.
  // Anche in questa funzione per esigenze di test uso srand() e rand()
  BBSSetup(100);
  //
  
  for(i=0;i<r;i++){
    // Calcola gli 8 bit e aggiorna per il prossimo bit
    byte[i]=BBSByte();
    //
    
    printf("%02d) ",i);
    print8bit(byte[i]);
    printf("\n");

  }
  //

  // Ripulisce la memoria dai big number
  BBSEnd();
  //

  // Verifica se numero di "1" e "0" è simile.	//ce lo aspettiamo se il numero è un "buon" random.
  for(i=0;i<r;i++){
    HammingSum+=Hw(byte[i]);
    print8bit(byte[i]);
  }
  printf("\n");
  printf("nr 1=%d, nr 0=%d\n",HammingSum,8*r-HammingSum);
  //
}


