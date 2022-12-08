/*
  gcc -c PrimeLib.c
  gcc PrimeTest.c -o PrimeTest PrimeLib.o -lgmp
  ./PrimeTest 6 3 (to Launch RSAPrime)
*/

#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>
#include<inttypes.h>
#include<stdint.h>
#include "PrimeLib.h"

int main(int argc, char * argv[]){
  int s;
  mpz_t p; mpz_init(p);
  mpz_t e; mpz_init(e);
  mpz_set_ui(e,3); 
 

  // Set a stupid seed. We are not interested now in entropy.
  // We use rand() in BBSPrime. Hence with srand(0) we have a test vector using m=1024;
  
  srand(4);
  if(argc != 2)  printf("%s 1 (or 2 or 3)\n1: randPrime \n2: BBSPrime \n3: RSAPrime\n", argv[0]);
  else{
  s=atoi(argv[1]);
  
  switch(s){
  case 1: randPrime(p); break;
  case 2: BBSPrime(p); break;
  case 3: RSAPrime(p,e); break;
  default: printf("Wrong case \n");
  }
  // Print p
  printf("The prime p is: ");
  mpz_out_str(stdout,16,p);
  printf ("\n");
 

  mpz_clear(p);
  mpz_clear(e);
  }
}
