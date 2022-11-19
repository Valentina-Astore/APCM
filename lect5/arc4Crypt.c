/* To compile
 * 1) gcc arc4Lib.c -c 
 * 2) gcc arc4Crypt.c -o arc4Crypt arc4Lib.o
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "arc4Lib.h"


void main(int argc, char *argv[]) {
  char key[MAXKEY];
  char fileout[MAXFILE];
  FILE *fpout;

  if(argc!=3){
    printf("%s key fileout\n", argv[0]);
    return;
  } else {
    strcpy(key,argv[1]);
    strcpy(fileout,argv[2
]);
  }
  fpout=fopen(fileout,"w");
  // Prendo un carattere alla volta e lo cripto su fileout
  uint8_t buf[MAXBUF];
  uint8_t out;
  char c;


  arc4Setup(key, strlen(key));

  while((c=getchar())!=EOF){
    out=arc4TranslateByte(c);  
    putc(out,fpout);
   }
  //
  
  fclose(fpout);
  return;
}
