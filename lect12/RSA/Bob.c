/*
 * gcc RSA.c -o RSA RSA.Lib.o -lgmp
 */


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
  // da mettere in readPublicKeyFromFile
  mpz_t M;  mpz_init(M);
  mpz_t C;  mpz_init(C);

  mpz_init(Pk.n);
  mpz_init(Pk.e);   
  //

  publicKey Pk;

  // Initialize public key
  readPublicKeyFromFile(&Pk);

  //Scrivere funzione showPublicKey()  
  printf("Pk.n=%s\n", mpz_get_str(NULL, 16, Pk.n));
  printf("Pk.e=%s\n", mpz_get_str(NULL, 16, Pk.e));
  printf("\n");
  //

  i=0;
  printf("Insert a message: (ENTER+Ctrl->D to end):\n");
  while((buf[i]=getchar())!=EOF && i<BLOCK_IN_BYTE-1){
    i++;
  }

  buf[i]='\0';

  // Crea il "bigint" messaggio M
  mpz_import(M, i, 1, sizeof(buf[0]), 0, 0, buf);
  //
 

  
  printf("original is [%s]\n", mpz_get_str(NULL, 16, M)); 
  // Cripta il messaggio
  encrypt(C, M, Pk);
  //


  // Salva su file in formato esadecimale
  char file[]="SMS.cry";
  FILE *fpsms;
  fpsms=fopen(file,"w");
  fprintf(fpsms,"%s", mpz_get_str(NULL,16, C));
  fclose(fpsms);
  //

  printf("encrypted is [%s]\n", mpz_get_str(NULL, 16, C));

  // Scrivere funzione clearPublicKey(&Pk)
  mpz_clear(Pk.n);
  mpz_clear(Pk.e);
  //

  mpz_clear(C);
  mpz_clear(M);


  
  return 0;
}
