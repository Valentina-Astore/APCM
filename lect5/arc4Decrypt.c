#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "arc4Lib.h"


void main(int argc, char *argv[]) {
  char key[20];
  char filein[80];
  FILE *fpin;

  if(argc!=3){
    printf("%s key filein\n", argv[0]);
    return;
  } else {
    strcpy(key,argv[1]);
    strcpy(filein,argv[2]);
  }
  fpin=fopen(filein,"r");

  // Prende i bytes da filein e li stampa a video
  char out;
  int c;
  arc4Setup(key, strlen(key));

  while((c=getc(fpin))!=EOF){
    out=arc4TranslateByte(c);  
    printf("%c",out);
  }
  // 
  return;
}
