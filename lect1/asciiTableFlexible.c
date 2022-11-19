/*
- Il passaggio dei parametri alla funzione main 
argc (argument count) e argv (arguments values or vector)
- conversione stringa intero
atoi
- funzione math.h
- IMPORTANTE: Compilazione con -lm
ceil
- casting
(float)
 */


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int maxcol,maxrow;
  if(argc==1){
    maxcol=12;
  } else { 
    maxcol=atoi(argv[1]);
  }
  maxrow=ceil((float)95/maxcol);
  int ch,col,row;
  ch=32;
  for(row=0;row<maxrow;row++){
    printf("||");
    for(col=0;col<maxcol;col++){
      if(ch<127){
	printf("%c|%3d||",ch,ch);
	ch++;
      } else printf(" |   ||");
    }
    printf("\n");
  }
}
