/*
 gcc fibonacci.c -o fibonacci -lgmp
*/
#include <stdio.h>
#include <gmp.h>

int main(){

  unsigned int i,iter ;
  
  // a[2]=a[0]+a[1]
  mpz_t a[3];

  printf("How many terms do you want o compute? ");
  scanf("%d",&iter);


  // Inizializziamo i valori a0=1 e a1=1. a2 sarà a0+a1.
  for(i=0;i<3;i++) mpz_init(a[i]);
  mpz_set_ui(a[0],1);
  mpz_set_ui(a[1],1);
  //

  printf ("0 -> 1\n" );
  printf ("1 -> 1\n" );
  


  for(i=0;i<iter;i++){
    // a[2]=a[0]+a[1]
    mpz_add(a[2],a[0],a[1]);

    printf ("%d -> ", i+2);
    // Stampiamo a2
    mpz_out_str(stdout,10,a[2]);
    printf ("\n");
    //
    // Aggiornamo a0 e a1 per il prossimo passo.
    mpz_set(a[0],a[1]);
    mpz_set(a[1],a[2]);
   }

  /* 6. Clean up the mpz_t handles or else we will leak memory */
  for(i=0;i<3;i++) mpz_clear(a[i]);
 
}
