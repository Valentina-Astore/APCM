#include "RSA.Lib.h"

void genKey(privateKey* Sk){
	
	
	mpz_init((*Sk).n);		mpz_init((*Sk).e);		mpz_init((*Sk).d);		mpz_init((*Sk).p);		mpz_init((*Sk).q);		 
	
	mpz_t temp;		mpz_init(temp);
	
	mpz_t threshold;	mpz_init(threshold);	mpz_ui_pow_ui(threshold,2,(MODN_IN_BIT/4));
        
    mpz_set_ui((*Sk).e,F4); 

    RSAPrime((*Sk).p, (*Sk).e);

	do{
		RSAPrime((*Sk).q, (*Sk).e);
		mpz_sub(temp, (*Sk).p, (*Sk).q);
	} while (mpz_cmpabs(temp,threshold) <= 0);
	
	
	//****************calculating d********************
	mpz_sub_ui((*Sk).p, (*Sk).p, 1);       mpz_sub_ui((*Sk).q, (*Sk).q, 1);  //p-1 and q-1
	
	mpz_mul(temp, (*Sk).p, (*Sk).q); //temp = phi
	mpz_add_ui((*Sk).p, (*Sk).p, 1);       mpz_add_ui((*Sk).q, (*Sk).q, 1);  //p and q
		
	mpz_invert((*Sk).d, (*Sk).e, temp);
	//****************end calculating d********************
	
	
	mpz_mul((*Sk).n, (*Sk).p, (*Sk).q);//calculating n
	
	mpz_clear(temp);
	mpz_clear(threshold);
}


void writeKeysOnFiles(privateKey* Sk){

//  opening the two files in write mode
    FILE *publicKeyFile;    publicKeyFile = fopen("./Public.key","w");
    FILE *secretKeyFile;    secretKeyFile = fopen("./Secret.key","w");

//  saving the private key parameters as hexadecimal strings
    fprintf(secretKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).n));
    fprintf(secretKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).e));
    fprintf(secretKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).d));
    fprintf(secretKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).p));
    fprintf(secretKeyFile, "%s", mpz_get_str(NULL, 16, (*Sk).q));
    
//  saving the public key parameters
    fprintf(publicKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).n));
    fprintf(publicKeyFile, "%s\n", mpz_get_str(NULL, 16, (*Sk).e));
    
//  closing the files
    fclose(publicKeyFile);
    fclose(secretKeyFile);
    
}



/*
void encrypt(mpz_t C, mpz_t M, publicKey Pk);
void decrypt(mpz_t M, mpz_t C, privateKey Sk);
void decryptCRT(mpz_t M, mpz_t C, privateKey Sk);

// On File


void readPublicKeyFromFile(publicKey *Pk);
void readPrivateKeyFromFile(privateKey *Sk);*/
