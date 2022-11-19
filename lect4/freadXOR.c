#include<stdio.h>
#include<stdint.h>
#include <inttypes.h>
#define MAXBUF 16

uint8_t * main(int argc, char * argv[])
{ 
  //choosing the file in input
  FILE * fpin = fopen(argv[1], "r");
  
  //defining the starting value of the sum
  static uint8_t XOR[16];
  for(int i=0; i<8; i++)XOR[i]=0;
  
  printf("%c\n", XOR[0]);
  

  uint8_t bufin[MAXBUF];for(int i=0; i<8; i++)bufin[i]=0;
  
  int nread;
  nread = fread(bufin,sizeof(uint8_t), MAXBUF, fpin);
  //do while on the blocks of the input file
  while(nread==16){

  printf("%c\n", bufin[0]);
  for(int i=0; i<16; i++)XOR[i]^=bufin[i];
  printf("%c\n", XOR[0]);
      nread = fread(bufin,sizeof(uint8_t), MAXBUF, fpin);
  }
  
  for(int i=0; i<nread-1; i++)XOR[i]^=bufin[i];
  


//XOR[nread-1]^=bufin[nread-1];//elimina il problema che viene preso come invio l'ultimo carattere'
  printf("%c\n", bufin[1]);
  printf("%c\n", bufin[2]);
  return XOR;
  



}
