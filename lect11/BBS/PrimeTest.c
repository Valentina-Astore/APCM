/*
  gcc -c PrimeLib.c
  gcc PrimeTest.c -o PrimeTest PrimeLib.o -lgmp
  PrimeTest 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <inttypes.h>
#include <stdint.h>
#include "PrimeLib.h"


int main(int argc, char * argv[]){

  int r,i,seed;
  mpz_t p; mpz_init(p);
 
  if(argc != 2)
    r=10;
  else
    r=atoi(argv[1]);

  for(i=0;i<r;i++){
    printf("------Test %d-----\n",i);

    // Calcolo il seed che serve per generare un numero random
    // randNum. Questo verrà utilizzato da randPrime.
    seed=(i+1)*10;
    srand(seed);
    randPrime(p); 
    printf("The random prime p is    : ");
    mpz_out_str(stdout,10,p);
    printf ("\n");

    // Con lo stesso seed precedentemente calcolato verifichiamo se il primo calcolato precedentemente è anche BBSPrime.

    srand(seed);
    BBSPrime(p); 
    printf("The random BBS prime p is: ");
    mpz_out_str(stdout,10,p);
    printf ("\n");      
  }

  mpz_clear(p);

}
