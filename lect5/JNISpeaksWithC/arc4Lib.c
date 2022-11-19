//define MAXBUF  655536
//define MAXKEY      40
//define MAXFILE     30
#include <stdio.h>
#include <stdint.h>

static uint8_t S[256];

void swap(uint8_t *a, uint8_t *b){
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
    }

void arc4Setup(const uint8_t key[], uint8_t len){
    for(int i = 0; i<256; i++) S[i] = i;
    uint8_t j = 0;
    for(int i = 0; i<256; i++) {
        j = (j + S[i] + key[i % len]);//j = (j + S[i] + key[i % len]) %  256;
        swap(&S[i],&S[j]);//in alternativa potresti mettere S+i, S+j con aritmetica dei puntatori
    }
}


void arc4PrintState(){
    for(int i = 0; i<16; i++){
        for(int j = 0; j<16; j++){
            printf("%02X. ", S[16*i+j]);
        }   
        printf("\n"); 
    }    
}


void arc4KeyStream(uint8_t out[], uint64_t len){
    uint8_t i = 0;
    uint8_t j = 0;
    for(int k = 0; k<len; k++){
        i++;
        j += S[i] ;
        swap(&S[i], &S[j]);
        out[k] = S[(S[i] + S[j]) & 255 ];    
    }
}




uint8_t arc4TranslateByte(uint8_t bytein){
    static uint8_t ii = 0, jj = 0;
    ii++;
    jj += S[ii] ;
    swap(&S[ii], &S[jj]);
    return S[(S[ii] + S[jj]) & 255 ] ^ bytein;
}
















