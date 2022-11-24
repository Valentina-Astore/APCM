#include <stdio.h>
#include <inttypes.h>
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


void encryptAESSimply(uint8_t buf[], int inlength, uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD]){

	uint8_t state[WORDS_IN_KEY][BYTES_IN_WORD];
	
	for(int k = 0; k < inlength; k+=16){
	
		for(int i = 0; i < WORDS_IN_KEY; i++){
			for(int j = 0; j < BYTES_IN_WORD; j++){
				state[i][j] = buf[k+(4*j+i)];
	  		}
		}
	
	
		addRoundKey(0, state, roundKey);
		for(int r = 1; r < NR_ROUNDS; r++){
			subBytes(state);
			shiftRows(state);
			addRoundKey(r, state, roundKey);		
		}

		subBytes(state);
		shiftRows(state);
		addRoundKey(NR_ROUNDS, state, roundKey);
	
	
		for(int i = 0; i < WORDS_IN_KEY; i++){
			for(int j = 0; j < BYTES_IN_WORD; j++){
				buf[k+(4*j+i)] = state[i][j];
	  		}
		}
	}



}
