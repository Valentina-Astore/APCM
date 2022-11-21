#include <stdio.h>
#include <inttypes.h>
#include "AES.Lib.h"
#include "AESStuff.c"

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
