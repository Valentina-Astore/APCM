/*
 * gcc AliceCRT.c -o AliceCRT PrimeLib.o RSA.Lib.o -lgmp
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gmp.h>
#include "RSA.Lib.h"
#include "PrimeLib.h"

int main(){
  char buf[BLOCK_IN_BYTE];
  char c;
  int i;
  mpz_t C;  mpz_init(C);
  mpz_t DC;  mpz_init(DC);
  privateKey Sk;

  // Initialize public key
  mpz_init(Sk.n);
  mpz_init(Sk.e);
  mpz_init(Sk.d);
  mpz_init(Sk.p);
  mpz_init(Sk.q);
 
  readPrivateKeyFromFile(&Sk);
 
  printf("Sk.n=%s\n", mpz_get_str(NULL, 16, Sk.n));
  printf("Sk.e=%s\n", mpz_get_str(NULL, 16, Sk.e));
  printf("Sk.d=%s\n", mpz_get_str(NULL, 16, Sk.d));
  printf("Sk.p=%s\n", mpz_get_str(NULL, 16, Sk.p));
  printf("Sk.q=%s\n", mpz_get_str(NULL, 16, Sk.q));
  printf("\n");
  
  char file[]="SMS.cry";
  FILE *fpsms;
  char temp[BLOCK_IN_BYTE * 2];

  fpsms=fopen(file,"r");
  fscanf(fpsms,"%s", temp);
  mpz_set_str(C,temp,16);
  fclose(fpsms);

 
  decryptCRT(DC, C, Sk);

  printf("decrypted is [%s]\n", mpz_get_str(NULL, 16, DC));
  mpz_export(buf, NULL, 1, sizeof(buf[0]), 0, 0, DC);

  i=0;
  printf("The decrypted message is:\n");

  while((buf[i]!='\0' && i<BLOCK_IN_BYTE-1)){
    printf("%c",buf[i]);
    i++;
  }
  printf("\n");

  mpz_clear(Sk.n);
  mpz_clear(Sk.e);
  mpz_clear(Sk.d);
  mpz_clear(Sk.p);
  mpz_clear(Sk.q);

  mpz_clear(C);
  mpz_clear(DC);


  return 0;    

}
