/*
 VERSIOONE INCOMPLETA E MODIFICATA DELLA LIBRERIA FATTA A LEZIONE.
 Le funzioni non necessarie sono state rimosse e la funzione di encryption è stata modificata in modalità CFB.
*/

#include "AES.Lib.h"
#include "AESStuff.c"

void printState(uint8_t state[4][4]){

	for(int i = 0; i < WORDS_IN_KEY; i++){
		for(int j = 0; j < BYTES_IN_WORD; j++){
			printf("%02X ", state[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}


void print8bit(uint8_t byte) {

	for(int i = 7; i > 0; i--) {
		printf("%c", ((byte >> i) & 1) ? '1' : '0');
	}
	printf("%c", (byte & 1) ? '1' : '0');
}


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

// CAMBIATO DA QUI --------------------------------------------------------------------------------


// Cifra un singolo blocco AES128 di dimensione BLOCK_SIZE.
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
		for(int j = 0; j < BLOCK_SIZE; j++){
			previousCiphertextBlock[j] = buf[j+(BLOCK_SIZE*(regularBlocks-1))];
		}
		
		encryptAES(previousCiphertextBlock, roundKey);
		shortXOR(buf+(BLOCK_SIZE*regularBlocks), previousCiphertextBlock, residuals);
	}
}

// A QUI ------------------------------------------------------------------------------------------

