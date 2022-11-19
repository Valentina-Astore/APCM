
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#include "A5.1.Lib.h"

void main(int argc, char *argv[]) {
  uint32_t i,start,stop;
  uint8_t NBR[3]={R1OUT+1,R2OUT+1,R3OUT+1}; //Number of bits of the registers
  int idp;
  if(argc==2){
    idp=atoi(argv[1]);
    start=0;
    stop=(0x01<<(NBR[idp]+1)) - 1;  
  } else if (argc==4) {
    idp=atoi(argv[1]);
    start=atoi(argv[2]);
    stop=atoi(argv[3]);
  }  else {
    printf("%s id_primitive (e.g. 0,1,2) [start stop] \n", argv[0]);
    return;
  }
  
  
  printf("-------\nNumer of Outputs:%d\n-------\n", stop-start);
  // Questa funzione assegna le costanti di preprocessore R1OUT,... ai 3 registri definiti in A5.1.Lib.c
  // struct registers R[3];
  setupRegisters();
  //
  for(i=0;i<stop;i++){
    printf("%09d:",i);
    // Stampa il registro identificato da idp
    printRegister(idp);
    printf("-->");
    // .. stampa il suo output 
    printOut(idp);
    
    printf("\n");
    //.. ed infine lo aggiorna.
    updateRegister(idp);
  }
  
}
