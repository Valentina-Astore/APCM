/**********************************************************************
 * RSA using GMP                                                      *
 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gmp.h>
#include "PrimeLib.h"

#define BLOCK_IN_BYTE (MODN_IN_BIT/8)  //Size of a block that gets en/decrypted at once

#define F4 65537                // 4th Fermat's number (2^2^4 + 1). Minimum requested by NIST

typedef struct {
  mpz_t n; // Modulo
  mpz_t e; // Esponente pubblico e-->encrypt
} publicKey;

typedef struct {
  mpz_t n; // ""
  mpz_t e; // ""
  mpz_t d; // Esponente privato d-->decrypt
  mpz_t p; // primo p 
  mpz_t q; // primo q 
} privateKey;

void genKey(privateKey* Sk); 
void encrypt(mpz_t C, mpz_t M, publicKey Pk);
void decrypt(mpz_t M, mpz_t C, privateKey Sk);
void decryptCRT(mpz_t M, mpz_t C, privateKey Sk);

// On File

void writeKeysOnFiles(privateKey* Sk);
void readPublicKeyFromFile(publicKey *Pk);
void readPrivateKeyFromFile(privateKey *Sk);
