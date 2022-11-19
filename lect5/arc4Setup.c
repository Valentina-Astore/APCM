#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "arc4Lib.h"

void main(int argc, char *argv[]) {
  char key[MAXKEY];
  char fileout[MAXFILE];
  FILE *fpout;

  if(argc!=2){
    printf("%s key\n", argv[0]);
    return;
  } else {
    strcpy(key,argv[1]);
  }
  // In questo caso facciamo il solo setup dell'array state
  arc4Setup(key, strlen(key));
  arc4PrintState();

  return;
}
