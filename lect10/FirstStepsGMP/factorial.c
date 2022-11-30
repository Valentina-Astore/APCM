/*
 gcc factorial.c -o factorial -lgmp
*/
#include <stdio.h>
#include <gmp.h>

int main(){

  unsigned int nInput,i ;
  
  mpz_t n;
  unsigned int ndec;

  printf ("Enter your number: ");
  scanf("%d" , &nInput); 

  // Inizializzo n e lo pongo uguale a nInput
  mpz_init(n);
  mpz_set_ui(n,nInput);
  //
  
  // Ne stampo il valore
  printf ("n = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");
  //
  
  ndec=nInput-1;

  
  for(i=nInput-1;i>1;i--){
    mpz_mul_ui(n,n,ndec);
    ndec--;
   }


  printf ("n! = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");

  // Importante liberate la memoria!
  mpz_clear(n);

}
