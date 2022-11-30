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
  /* 
     Le due variabili seguenti sono legate alle pipe aperte in lettura/scrittura.
     In particolare il comando open nello standard POSIX (vedi Wiki) usa int (è diverso da fopen ANSI)
     In particolare mi permette di aprire e gestire in modo più preciso file speciali come le pipe.
  */
  int fpIn;
  int fpOut;
  //

  
  char fileNameIn[20];
  char fileNameOut[20];
  uint8_t key[MAXKEY];
  uint8_t len;
  int id;
  uint8_t buf[MAXBUF];
  if(argc!=3){
    printf("%s id key\n", argv[0]);
    return 1;
  } else {
    id=atoi(argv[1]);
    strcpy(key,argv[2]);
    //sprintf crea la stringa in fileNameIn/Out, e si comporta in modo analogo a printf
    sprintf(fileNameIn ,"Java2C%03d", id);
    sprintf(fileNameOut,"C2Java%03d", id);
    //
    
  }

  // Sarebbe stato meglio mettere
  //  arc4Setup(1, key, strlen(key));
  arc4Setup(id, key, strlen(key));

  //Ecco l'uso di open POSIX. Una Pipe la apro in lettura, l'altra in scrittura.
  // Attenzione qui ci vorrebbe un cntrollo sull'esistenza delle pipe
  fpIn=open(fileNameIn,O_RDONLY);
  fpOut=open(fileNameOut,O_WRONLY);
  //
  
  do {
    // Leggo sulla pipe quanti numeri devo generare 
    read(fpIn,buf,1);
    //    printf("C ha letto %d\n", buf[0]);
  
    len=(uint8_t)buf[0];
    // Se len>0 li genero ...
    if(len>0){
      arc4KeyStream(id, buf, len);

      
  
      write(fpOut,buf,len);

      /* printf("E ha scritto:\n"); */
      /* for(int i=0;i<len;i++) printf("%02X ",buf[i]); */
      //printf("\n");
    };

  } while(len!=0); //altrimenti esco
  close(fpOut);
  close(fpIn); 
  return 0;
}
