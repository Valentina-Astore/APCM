#include <inttypes.h>
#include <stdio.h>

void print8bit(uint8_t byte){
  int i;
  for (i = 7; i >=0 ; i--) {
    printf("%c", ((byte >> i) & 1) ? '1' : '0');
  }
}


// Questo programma visualizza il primo ed il secondo nibble di un byte inserito dall'utente.
// Inoltre presenta un esempio di costanti per l'input e l'output (SCNu8/PRIu8).

int main(void) {
  uint8_t num,comp;
  // Possiamo utilizzare le seguenti costanti. Le prime in formato decimale. Senza prefisso.
  //  uint8_t mask4_1=15,mask4_2=240;
  // Le seconde in formato esadecimale. Con prefisso 0x.
 
  uint8_t mask4_1=0x0F,mask4_2=0xF0;
  printf("Insert a number N in (0-255):");
  // Nota che SCNu8 è una costante che completa la stringa "%". Il preprocessore la sostiurà ad esempio con "d"
  scanf("%" SCNu8,&num); //COMPLICAT0! vuole dire: prendi in input da tastiera un valore, interpretalo come unsigned integer (qui )
  // In modo analogo si comporterà con PRIu8
  printf("The inserted number is %"PRIu8"\n",num);
  printf("That in binary format is :");
  print8bit(num);
  printf("\n");

  printf("\n");
 
  printf("Its first nibble (4 bits) is \n");
  print8bit(mask4_1&num);
  printf("\n");
  printf("Its second nibble is\n");
  print8bit(mask4_2&num);
  printf("\n");
  
  return 0;
}
