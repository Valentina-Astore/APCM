#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gmp.h>
#include "RSA.Lib.h"

int main() {
    privateKey Sk;

    genKey(&Sk);

    // showKey()
    printf("---------------Private Key (Hex) ------------------\n");
    printf("Sk.n=%s\n", mpz_get_str(NULL, 16, Sk.n));
    printf("Sk.e=%s\n", mpz_get_str(NULL, 16, Sk.e));
    printf("Sk.d=%s\n", mpz_get_str(NULL, 16, Sk.d));
    printf("Sk.p=%s\n", mpz_get_str(NULL, 16, Sk.p));
    printf("Sk.q=%s\n", mpz_get_str(NULL, 16, Sk.q));
    printf("\n");
    //

}


