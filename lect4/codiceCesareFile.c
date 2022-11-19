#include<stdio.h>
#include <stdlib.h>

void main(int argc, char*argv[]){

  //chiave
  int key = atoi(argv[1]);

  //file in input
  FILE * fpin = fopen(argv[2], "r");
  
  //file in putput
  FILE * fpout = fopen(argv[3], "w");

  // cicliamo sui byte del file in input
  int c;
  while((c=getc(fpin))!=EOF)//prendiamo un byte e, se diferso da fine file, eseguiamo la linea seguente
  {
    //inseriamo nel nuovo file il byte opportunamente traslato
    if(c>31 && c < 127)putc(((c-32+key)%95)+32, fpout);
    else putc(c, fpout);
    
  }

  fclose(fpin);
  fclose(fpout);
    
 
}
