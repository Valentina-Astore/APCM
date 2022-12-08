#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <inttypes.h>
#include <stdint.h>
#include "PrimeLib.h"
#include "BBSLib.h"

mpz_t n;
mpz_t x;

void BBSSetup(int seed){

	srand(seed);

	mpz_init(n);
	mpz_init(x);
	
	mpz_t p;	mpz_init(p);
	mpz_t q;	mpz_init(q);

	BBSPrime(p);
	BBSPrime(q);
	
	mpz_mul(n,p,q);
	
	mpz_clear(p); mpz_clear(q);
	
	mpz_t g;	mpz_init(g);
	do {
		randNum(x);
		mpz_gcd(g,x,n);
	} while(mpz_cmp_ui(g,1) != 0);
	
	mpz_clear(g);
}


uint8_t outBit(){

	return mpz_odd_p(x);
}


void nextX(){	mpz_powm_ui(x,x,2,n);	}


uint8_t BBSByte(){

	uint8_t out = outBit();
	nextX();
	for(uint8_t i = 1; i < 8; i++) {
	
		out = out << 1;
		out ^= outBit();
		nextX();
	}
	
	return out;
}


void BBSEnd(){

	mpz_clear(n);
	mpz_clear(x);
}

