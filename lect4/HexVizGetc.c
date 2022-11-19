/*
 getc(fpin) prende un char da fpin fino a che ho un EOF.
 fpin è un puntatore ad un file. (*) 
 Se il nome file non è stato passato come argomento pongo fpin=stdin, dove stdin è una costante di stdio che indica lo "standard input". (**)
*/

#include <stdio.h>
int main(int argc, char *argv[]){
  int c;

  FILE *fpin; //(*)
  

  if(argc==1){
    fpin=stdin; //(**)
  } else if(argc==2){
    fpin=fopen(argv[1],"r");
  } else {
    printf("%s [filein]\n", argv[0]);
    return 0;
  }
  while((c=getc(fpin))!=EOF){
    if(c>=32 && c<=126)
      printf("%c %2X\n",c,c);
    else
      printf("  %2X\n",c);
  }
}


