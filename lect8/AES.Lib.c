#include <stdio.h>
#include <inttypes.h>
#include "AES.Lib.h"
#include "AESStuff.c"

void roundKeyGen(uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD], uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]){
	
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			roundKey[0][i][j] = Key[i][j];
		}
	}
	
	
	for(int i = 1; i <= NR_ROUNDS; i++){
		
		// Prima word (prima riga di roundKey[i])
		for(int k = 0; k < 4; k++) {
			roundKey[i][0][(k-1)%4]	= SBox[roundKey[i][0][k]];
		}
		
		roundKey[i][0][0] ^= RCon[i];
		
		// Successive 3 righe di roundKey[i]
		for(int j = 1; j < 4; j++) {
			for(int k = 0; k < 4; k++){
				roundKey[i][j][k] = roundKey[i][j-1][k] ^ roundKey[i-1][j][k];
			}
		}
	}


}
