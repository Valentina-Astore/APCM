// Vedi PrimeLib.h in BBS per comprendere queste due costanti
#define MODN_IN_BIT 1024
#define BIGNUM_IN_BYTE (MODN_IN_BIT/16)  //Prime Size in Bytes
//



void randNum(mpz_t n);
void randPrime(mpz_t p);
void BBSPrime(mpz_t p);
void RSAPrime(mpz_t p, mpz_t e);
