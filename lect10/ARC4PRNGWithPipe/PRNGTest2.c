#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "arc4Lib.h"

// In questo caso facciamo il setup dell'array state e
// usiamo l'algoritmo come PRNG di len byte.
int main(int argc, char *argv[]) {

  int fp;
  // nome della named pipe  

  int fpIn;
  int fpOut;
  
  char *fileNameOut="Java2C001";
  char *fileNameIn="C2Java001";

  uint8_t len=16;
  uint8_t buf[MAXBUF];


  // Dico a PRNG quanti numeri casuali mi deve inviare
  
  // Apro e chiudo ogni volta per evitare un deadlock sulla risorsa "pipe"
  fpOut=open(fileNameOut,O_WRONLY);
  fpIn=open(fileNameIn,O_RDONLY);

  for(int j=0;j<100000;j++){
    buf[0]=len;
    write(fpOut,buf,1);
    // Appena PRNG ha generato i numeri e li scritti sulla pipe li leggo
  
    read(fpIn,buf,len);
    //
    // E li stampo
    for(int i=0;i<len;i++){ 
      printf("%02X ", buf[i]); 
    };
    printf("\n");
  //
  }
    
  close(fpIn);
  close(fpOut);
  
  //



  
  // fputc(0,fpOut); 
   
  /* fclose(fpIn); */
  /* fclose(fpOut); */
  //  close(fpIn);
  //  close(fpOut);

 
  return 1;
}
