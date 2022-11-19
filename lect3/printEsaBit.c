/*
  -inttypes.h
  Uso di inttypes per portabilità dei tipi interi su architetture diverse 
 */
#include <stdio.h>
#include <inttypes.h>


void print8bit(uint8_t byte);
void printcomp(uint8_t byte);
void print6(uint8_t byte);


int main() {
  uint8_t i=0;
  // Stampiamo tutti i byte da 0 a 255.
  do {
    /*
    %03d -> Stampo un numero decimale di 3 cifre preceduto da 0 (se necessario per riempire i 3 spazi)
    %2X  -> Stampo un numero esadecimale di 2 cifre 
    */
    printf("%03d %2X ",i,i);
    // Purtroppo nel C ANSI non esiste una funzione per la stampa binaria => abbiamo dovuto implementarla noi.
    print8bit(i);
    
    printf("\n");
    i++;
    
  } while (i!=0); // Nota che qui sfrutto il "principio" dell'overflow. Sapendo che i è in [0,255], se i=255, i++ diventa 0! 
}


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


void printcomp(uint8_t byte)
{
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
    printf("%c", (~(byte >> i) & 1) ? '1' : '0');
  }

}



void print6(uint8_t byte)
{
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
    printf("%c", (~(byte >> i) & 1) ? '1' : '0');
  }

}

