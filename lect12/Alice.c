/*
 * gcc RSA.c -o RSA RSA.Lib.o -lgmp
 * 
 */

/**********************************************************************
 *                                                                    *
 *                                                                    *
 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gmp.h>
#include "RSA.Lib.h"

int main(){
  char buf[BLOCK_IN_BYTE];
  char c;
  int i;
  mpz_t C;  mpz_init(C);
  mpz_t DC;  mpz_init(DC);
  

  // Tutto questo dovrebbe andare in readPublicKeyfromFile()
  // Initialize public key
  mpz_init(Sk.n);
  mpz_init(Sk.e);
  mpz_init(Sk.d);
  mpz_init(Sk.p);
  mpz_init(Sk.q);
  //

  privateKey Sk;
  readPrivateKeyFromFile(&Sk);

  //showPublicKey() 
  printf("Sk.n=%s\n", mpz_get_str(NULL, 16, Sk.n));
  printf("Sk.e=%s\n", mpz_get_str(NULL, 16, Sk.e));
  printf("Sk.d=%s\n", mpz_get_str(NULL, 16, Sk.d));
  printf("Sk.p=%s\n", mpz_get_str(NULL, 16, Sk.p));
  printf("Sk.q=%s\n", mpz_get_str(NULL, 16, Sk.q));
  printf("\n");
  //
  
  //leggo SMS.cry
  char file[]="SMS.cry";
  FILE *fpsms;
  char temp[BLOCK_IN_BYTE * 2];

  fpsms=fopen(file,"r");
  fscanf(fpsms,"%s", temp);

  mpz_set_str(C,temp,16);   // Da una stringa ottengo un mpz_t
 

  fclose(fpsms);
  //

 
  decrypt(DC, C, Sk);

  // Stampo a video il messaggio decriptato
  printf("decrypted is [%s]\n", mpz_get_str(NULL, 16, DC));
  mpz_export(buf, NULL, 1, sizeof(buf[0]), 0, 0, DC);

  i=0;
  printf("The decrypted message is:\n");

  while((buf[i]!='\0' && i<BLOCK_IN_BYTE-1)){
    printf("%c",buf[i]);
    i++;
  }
  printf("\n");
  //

  // Usare una funzione per liberare la memoria occupata dalla chiave privata come in Bob.c  
  mpz_clear(Sk.n);
  mpz_clear(Sk.e);
  mpz_clear(Sk.d);
  mpz_clear(Sk.p);
  mpz_clear(Sk.q);
  //

  mpz_clear(C);
  mpz_clear(DC);

  return 0;

}
