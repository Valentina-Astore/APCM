//MODN_IN_BIT  è la lunghezza di n (in bit) in BBS e RSA
#define MODN_IN_BIT 1024   

// BIGNUM_IN_BYTE e' la dimensione dell'array di uint8_t che definisce randNum e dunque in modo indiretto
// tutte le altre funzioni che generano un primo di questa libreria.
// Essendo n=pq e p,q di lunghezza in bit simile, ottengo il valore
#define BIGNUM_IN_BYTE (MODN_IN_BIT/16)  //Prime Size in Bytes

// Genera un numero pseudo-random di BUFFER_SIZE bytes
// Che ha il MSB a 1 e il LSB fissati ad 1 (grande abbastanza e dispari)
void randNum(mpz_t m);	// il numero pseudo-random verrà salvato in randNum
// Genera un numero primo a partire da randNum
void randPrime(mpz_t p);
// Genera un numero primo usando randPrime
void BBSPrime(mpz_t p);
void RSAPrime(mpz_t p, mpz_t e);
