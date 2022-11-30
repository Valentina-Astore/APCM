#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/random.h>

uint8_t Hw(uint8_t word){
  uint8_t Hw=0,bit=word,i;
  
  for (i=0; i<8; i++) {
    if (bit & 1) Hw++;
    bit = (bit >> 1);
  }
  return Hw;
}

void print8bit(uint8_t byte){
  int i;
  for (i = 7; i >=0 ; i--) {
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  }
}

int main(){
  int seedSize = 64; // massimo 256
  char seed[seedSize];
  int err;
  int HammingSum=0;
  // In seed restituisce l'entropia
  err = getentropy(seed, seedSize);
  if (err != 0) {
    printf("Errore\n");
  } else {
    for(int i=0;i<seedSize;i++){
      HammingSum+=Hw(seed[i]);
      print8bit(seed[i]);
      if(i%8==7) printf("\n");
    }
    printf("\n");
    printf("nr 1=%d, nr 0=%d\n",HammingSum,8*seedSize-HammingSum);
  }
}
