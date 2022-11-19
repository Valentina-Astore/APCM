#include <inttypes.h>
#include <stdio.h>

void print8bit(uint8_t byte){
  int i;
  for (i = 7; i >=0 ; i--) {
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  }
}


// Questo programma ruota di 1
// Inoltre presenta un esempio di costanti per l'input e l'output (SCNu8/PRIu8).

int main(void) {
  uint8_t num,comp;
  // Possiamo utilizzare le seguenti costanti. Le prime in formato decimale. Senza prefisso.
  // Le seconde in formato esadecimale. Con prefisso 0x.
 
  printf("Insert a number N in (0-255):");
  // Nota che SCNu8 è una costante che completa la stringa "%". Il preprocessore la sostiurà ad esempio con "d"
  scanf("%" SCNu8,&num);
  // In modo analogo si comporterà con PRIu8
  printf("The inserted number is %"PRIu8"\n",num);
  printf("That in binary format is :");
  print8bit(num);
  printf("\n");

  printf("\n");
  for(int i=0;i<=8;i++){
    printf("Rotated by %d it is   ", i);
    print8bit( (num << i) | ( num >> 8-i ) );
    printf("\n\n");
    }
  

  
  return 0;
}
