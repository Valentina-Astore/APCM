#include <inttypes.h>

#include <stdlib.h>
#include <stdio.h>
// Qui definisco i prototipi. Invece di inserirli ogni volta è utile creare un file .h.
// N.b. tutti gli altri file .h hanno la stessa struttura di quello che ho appena definito.
// Molto spesso nei file .h si inseriscono anche le costanti di preprocessore (e.g. #define COSTANTE 1000). 
// Usando le "" cerca nella cartella definita tra le virgolette. In questo caso è quella corrente.

#include "ByteLib.h"     //NB questo è messo tra virgolette e non tra angolate, questo implica che il file va cercato nella cartella corrente e non nella standard (potrei qui inserire un percorso più compilato)

int main() {
  uint8_t start; 
  printf("Insert the starting byte :");
  scanf("%" SCNu8,&start);

  printf("Il peso di Hamming del byte inserito è %"PRIu8"!\n", Hw(start));
  
  uint8_t registro= start;
  uint8_t clock= 0; 

  do{
    printf("%3d:", ++clock);
    print8bit(registro);
    printf("\n");
    registro=rotatelt8bit(registro);
  }while(registro!=start);
  printf("\n");
  return 0;
}


