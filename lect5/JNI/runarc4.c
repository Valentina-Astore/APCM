#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "arc4Lib.h"

// arcPRNG.h è il file autogenerato tramite il comando
// javah arc4PRNG (penso .class?!!)
#include "arc4PRNG.h"
// Il nome della funzione (il suo protocollo o firma)
// l'ho preso da arc4PRNG.h
JNIEXPORT void JNICALL
Java_arc4PRNG_runarc4(JNIEnv *env, jobject obj){

  
  uint8_t buf[MAXBUF];
  uint8_t key[]={'p','i','p','p','o'};
  int keylength=5;
  int len=15; // Numero di bytes random
  arc4Setup(key, keylength);
  arc4KeyStream(buf, len);
  return;
}

