#include <inttypes.h>
#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include "PrimeLib.h"

void randNum(mpz_t m){

	uint8_t buf[BIGNUM_IN_BYTE];
	for(int i = 0; i < BIGNUM_IN_BYTE; i++) buf[i] =rand();

	buf[0] |= 0x80;
	buf[BIGNUM_IN_BYTE-1] |= 1;

	mpz_import(m, BIGNUM_IN_BYTE, 1, sizeof(uint8_t), 0, 0, buf);
}


void randPrime(mpz_t p){

	randNum(p);
	mpz_nextprime(p,p);
}


void BBSPrime(mpz_t p){

	mpz_t c;
	mpz_init(c);

	randPrime(p);
	mpz_mod_ui(c,p,4);
	while (mpz_cmp_ui(c,3) != 0) {
		//mpz_out_str(stdout, 4, c);
		//printf("  ");
		mpz_nextprime(p,p);
		//mpz_out_str(stdout, 4, p);
		//printf("\n\n");
		mpz_mod_ui(c,p,4);
	}
	
	mpz_clear(c);
}

