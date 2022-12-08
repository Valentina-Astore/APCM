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

int main()
{
    int i;
    privateKey Sk;
    publicKey Pk;

    // Initialize public key
    mpz_init(Pk.n);
    mpz_init(Pk.e); 
    // Initialize private key
    genKey(&Sk);

    printf("---------------Private Key (Hex) ------------------\n");
    printf("Sk.n=%s\n", mpz_get_str(NULL, 16, Sk.n));
    printf("Sk.e=%s\n", mpz_get_str(NULL, 16, Sk.e));
    printf("Sk.d=%s\n", mpz_get_str(NULL, 16, Sk.d));
    printf("Sk.p=%s\n", mpz_get_str(NULL, 16, Sk.p));
    printf("Sk.q=%s\n", mpz_get_str(NULL, 16, Sk.q));
    printf("\n");
    
    writeKeysOnFiles(&Sk);
    // clearSecretKey(&Sk)
    mpz_clear(Pk.n);
    mpz_clear(Pk.e);

    mpz_clear(Sk.n);
    mpz_clear(Sk.e);
    mpz_clear(Sk.d);
    mpz_clear(Sk.p);
    mpz_clear(Sk.q);
    //
    
    

}


