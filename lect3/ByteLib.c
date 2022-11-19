#include <inttypes.h>

#include <stdlib.h>
#include <stdio.h>


void print8bit(uint8_t byte){//funzione per la stampa binaria
  int i;

  for (i = 7; i >=0 ; i--) {
    /*
      Spieghiamo la condizione inline ((byte >> i) & 1) ? '1' : '0'

      1) (byte >> i) -> shift a destra del byte di i posizioni
      2) Faccio un and con "1"
      3) Se il bit shiftato nella prima posizione è 1 allora 
                      XXXXXXX1 &
		      00000001 =
		      00000001
	 Se il bit shiftato nella prima posizione è 0 allora ottengo 0.

      4) Stampo nel primo caso '1', '0' nel secondo.
    */
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  }
}




uint8_t rotatelt8bit(uint8_t byte){
    return (byte <<1) | (byte >>7); 
}

uint8_t Hw(uint8_t word){
    uint8_t w = 0;
    for(int i = 0; i <= 7; i++){
        if ((word >> i) & 1)  {w++;}
    }
    return w;
}
