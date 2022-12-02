/*
 VERSIOONE INCOMPLETA E MODIFICATA DELLA LIBRERIA FATTA A LEZIONE.
 Le funzioni non necessarie sono state rimosse e la funzione di encryption è stata modificata in modalità CFB.
*/

#include "AES.Lib.h"


// ---------- Parametri globali ----------

uint8_t SBox[256] = {
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

uint8_t RCon[] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };



// ---------- Generazione chiave ----------

void roundKeyGen(uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD], uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]){
	
	for(int i = 0; i < WORDS_IN_KEY; i++){
		for(int j = 0; j < BYTES_IN_WORD; j++){
			roundKey[0][i][j] = Key[i][j];
		}
	}
	
	for(int i = 1; i <= NR_ROUNDS; i++){
		
		// Prima word di roundKey[i] (prima riga di roundKey[i])
		for(int k = 0; k < BYTES_IN_WORD; k++) {
			roundKey[i][0][k] = SBox[roundKey[i-1][3][(k+1) % BYTES_IN_WORD]] ^ roundKey[i-1][0][k];
		}
		
		roundKey[i][0][0] ^= RCon[i];
		
		// Successive 3 righe di roundKey[i]
		for(int j = 1; j < WORDS_IN_KEY; j++) {
			for(int k = 0; k < BYTES_IN_WORD; k++){
				roundKey[i][j][k] = roundKey[i][j-1][k] ^ roundKey[i-1][j][k];
			}
		}
	}
}



// ---------- Funzioni di round AES ----------

void addRoundKey(uint8_t r, uint8_t state[4][4] , uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD]){

	for(int i = 0; i < BYTES_IN_WORD; i++){
		for(int j = 0; j < WORDS_IN_KEY; j++){
		
			// Modifichiamo l'i-esimo byte della j-esima parola.
			state[i][j] ^= roundKey[r][j][i];		
		}
	}
}


void subBytes(uint8_t state[4][4]){

	for(int i = 0; i < WORDS_IN_KEY; i++){
		for(int j = 0; j < BYTES_IN_WORD; j++){
			state[i][j] = SBox[state[i][j]];
		}	
	}
}


void shiftRows(uint8_t state[4][4]){
	
	uint8_t temp[3];
	
	for(int i = 1; i < BYTES_IN_WORD; i++){
	
		for(int j = 0; j < i; j++){
			temp[j] = state[i][j];
		}
		
		for(int j = 0; j < WORDS_IN_KEY-i; j++){
			state[i][j] = state[i][j+i];
		}
	
		for(int j = WORDS_IN_KEY-i; j < WORDS_IN_KEY; j++){
			state[i][j] = temp[j-WORDS_IN_KEY+i];
		}
	}
}


uint8_t xtime(uint8_t x) { return (x<<1)^(0X1B*(x>>7)); }


uint8_t multiplyF_256(uint8_t a, uint8_t b){

	uint8_t output = (b&(0x01))*a;
	
	for(uint8_t j = 1; j < 8; j++){
		a = xtime(a);
		output ^= ((b>>j)&(0x01))*a;
	}
	
	return output;

}


void mixColumns(uint8_t state[4][4]){

	uint8_t a[4] = {0x2, 0x3, 0x1, 0x1};
	
	// alla j-esima iterazione riempiamo la j-esima colonna di state
	for(uint8_t j = 0; j < WORDS_IN_KEY; j++) {
		
		uint8_t b[BYTES_IN_WORD];
		
		for (uint8_t i = 0; i < BYTES_IN_WORD; i++) {
			b[i] = state[i][j];
		}
			
		// ciclo per effettuare i 4 prodotti riga-colonna
		for(int k = 0; k < WORDS_IN_KEY; k++) {
		
			uint8_t temp = 0;
			
			for(int i = 0; i < BYTES_IN_WORD; i++) {
				temp ^= multiplyF_256(a[(4+i-k)%4], b[i]);
			}
			
			state[k][j] = temp;
		}	
	}	
}



// ---------- Definizione di AES in CFB mode ----------

// Cifra un singolo blocco AES128 di dimensione BLOCK_SIZE. Il blocco di plaintext ricevuto viene sovrascritto con il relativo blocco cifrato.
void encryptAES(uint8_t buf[], uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD]){

	uint8_t state[WORDS_IN_KEY][BYTES_IN_WORD];
	for(int i = 0; i < WORDS_IN_KEY; i++){
		for(int j = 0; j < BYTES_IN_WORD; j++){
			state[i][j] = buf[4*j+i];
  		}
	}

	// Whitening.
	addRoundKey(0, state, roundKey);
	
	// NR_ROUNDS-1 rounds completi.
	for(int r = 1; r < NR_ROUNDS; r++){
		subBytes(state);
		shiftRows(state);
		mixColumns(state);
		addRoundKey(r, state, roundKey);		
	}

	// Ultimo round atipico.
	subBytes(state);
	shiftRows(state);
	addRoundKey(NR_ROUNDS, state, roundKey);

	for(int i = 0; i < WORDS_IN_KEY; i++){
		for(int j = 0; j < BYTES_IN_WORD; j++){
			buf[4*j+i] = state[i][j];
  		}
	}
}


// Ritorna lo XOR degli input sovrascrivendo il primo dei due.
void XOR(uint8_t buf[BLOCK_SIZE], uint8_t vec[BLOCK_SIZE]) {

	for(int i = 0; i < BLOCK_SIZE; i++){
		buf[i] ^= vec[i];
	}
}

// Ritorna lo XOR degli input sovrascrivendo il primo dei due (di dimensione len < BLOCK_SIZE).
void shortXOR(uint8_t buf[], uint8_t vec[BLOCK_SIZE], int len) {

	for(int i = 0; i < len; i++){
		buf[i] ^= vec[i];
	}
}


// Cifra un intero buffer di plaintext usando AES128 in modalità CFB. Il buffer viene sovrascritto con il ciphertext ottenuto.
void encryptCFB(uint8_t buf[], int inlength, uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD]){
 
	// Numero blocchi di dimesione BLOCK_SIZE completi. La divisione ritona automaticamente il floor.
	int regularBlocks = inlength/BLOCK_SIZE;
	
	uint8_t previousCiphertextBlock[BLOCK_SIZE];
	for(int j = 0; j < BLOCK_SIZE; j++){
		previousCiphertextBlock[j] = iv[j];
	}
	
	for(int i = 0; i < regularBlocks; i++) {

		
		encryptAES(previousCiphertextBlock, roundKey);	
		XOR(buf+(BLOCK_SIZE*i), previousCiphertextBlock);
		
		for(int j = 0; j < BLOCK_SIZE; j++){
			previousCiphertextBlock[j] = buf[j+(BLOCK_SIZE*i)];
		}
	}
	
	int residuals = inlength - (regularBlocks*BLOCK_SIZE);	// dimensione del blocco finale (< BLOCK_SIZE).
	if (residuals != 0){
		if (regularBlocks != 0){
			for(int j = 0; j < BLOCK_SIZE; j++){
				previousCiphertextBlock[j] = buf[j+(BLOCK_SIZE*(regularBlocks-1))];
			}
		}
		encryptAES(previousCiphertextBlock, roundKey);
		shortXOR(buf+(BLOCK_SIZE*regularBlocks), previousCiphertextBlock, residuals);
	}
}


// Decifra un intero buffer di ciphertext usando AES128 in modalità CFB. Il buffer viene sovrascritto con il messaggio ottenuto.
void decryptCFB(uint8_t buf[], int inlength, uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD]){
 
	// Numero blocchi di dimesione BLOCK_SIZE completi. La divisione ritona automaticamente il floor.
	int regularBlocks = inlength/BLOCK_SIZE;
	
	uint8_t encryptedtBlock[BLOCK_SIZE];
	uint8_t previousCiphertextBlock[BLOCK_SIZE];
	for(int j = 0; j < BLOCK_SIZE; j++){
		previousCiphertextBlock[j] = iv[j];
	}
	
	for(int i = 0; i < regularBlocks; i++) {
		
		for(int j = 0; j < BLOCK_SIZE; j++){
			encryptedtBlock[j] = previousCiphertextBlock[j];
		}
		
		encryptAES(encryptedtBlock, roundKey);
		
		for(int j = 0; j < BLOCK_SIZE; j++){
			previousCiphertextBlock[j] = buf[j+(BLOCK_SIZE*i)];
		}
		
		XOR(buf+(BLOCK_SIZE*i), encryptedtBlock);

	}
	
	int residuals = inlength - (regularBlocks*BLOCK_SIZE);	// dimensione del blocco finale (< BLOCK_SIZE).
	if (residuals != 0){
		
		encryptAES(previousCiphertextBlock, roundKey);
		
		shortXOR(buf+(BLOCK_SIZE*regularBlocks), previousCiphertextBlock, residuals);

	}
}

