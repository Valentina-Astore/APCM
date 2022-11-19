#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arc4Lib.h"

// In questo caso facciamo il setup dell'array state e
// usiamo l'algoritmo come PRNG di len byte.
void main(int argc, char *argv[]) {
  // Da modificare in char problema con i Mac (comunque più elegante)
  uint8_t key[MAXKEY];
  int len;
  uint8_t buf[MAXBUF];
  if(argc!=3){
    printf("%s key len\n", argv[0]);
    return;
  } else {
    strcpy(key,argv[1]);
    len=atoi(argv[2]);
  }
 
  arc4Setup(key, strlen(key));
  // Per Visualizzare la casualita' del flusso di bit generati da ARC4
  arc4KeyStream(buf, len);
  for(int i =0; i<len; i++)printf("%02X. ", buf[i]);
  return;
}
