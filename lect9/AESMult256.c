/*

 */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "AES.Lib.h"


uint8_t HexToNibble(char Hex){
  if(Hex>='0'&& Hex <='9')
    return Hex-'0';
  else if(Hex>='A'&& Hex <='F')
    return Hex-'A'+10;
  else if(Hex>='a'&& Hex <='f')
    return Hex-'a'+10;
  else return 16;
}

uint8_t HexToBytes(char Hex[],int dimHex, uint8_t Byte[]){
  int i=0;
  uint8_t n0,n1;
  char r0,r1;
  char Ok=1;
  while(Ok && i<dimHex){
    r1=HexToNibble(Hex[i]);
    r0=HexToNibble(Hex[i+1]);
    if(r0<16 && r1<16)
      Byte[i/2]=r1*16+r0;
    else
      Ok=0;
    i+=2;
  }
  return Ok;
}

int main(int argc, char *argv[]) {
  //uint8_t a=0x53;
  //  uint8_t b=0xCA;
  uint8_t a=0,b=0;
  uint8_t Niba,Nibb;


  //  char sa[],sb[3];

  if(argc!=3){
    printf("%s a b\n", argv[0]);
    return 1;
  }
  if(strlen(argv[1])!=2  || strlen(argv[2])!=2){
    printf("Error: The product is between Hex of 2 digits\n");
    return 1;
  }

  int i;


  
  i=0;
  while(i<2 && (Niba=HexToNibble(argv[1][i]))<16 && (Nibb=HexToNibble(argv[2][i]))<16) {
    a=a<<4;
    b=b<<4;
    
    a^=Niba;
    b^=Nibb;
    i++;
  }
  if(Niba==16 || Niba==16  ){
    printf("Error: Digits must have Hexadecimal format!\n");
    return 1;
  }



  uint8_t c=multiplyF_256(a,b);
  
  printf("%02X\n", c);
  //    print8bit(in[i]);
  //  printf("\n");

}


