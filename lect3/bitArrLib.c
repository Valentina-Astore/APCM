#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

// Crea in modo dinamico un array di bit
uint64_t* bitArray(uint64_t dim){
    //uint64_t num = (dim & ~((uint64_t) 0x3F))+1;
    uint64_t num = ((dim-1) >> 6)+1;   
    return calloc( num ,  sizeof(uint64_t) );
}

void setBit(uint64_t A[], uint64_t ind,uint8_t bitval){
    uint64_t div = ind >> 6 ; //quoziente della divisione
    uint64_t mod = ind & ((uint64_t) 0x3F); //modulo della divisione
    uint64_t mask = ((uint64_t) 1) << (63-mod);
    
    //put to 0 the value of the ind-th bit 
    A[div] ^= (A[div] & mask);
    
    //put the desired value in the correct position if different from zero
    if ((_Bool)bitval) {A[div] ^= mask;}

}



uint8_t getBit(uint64_t A[], uint64_t ind){
    uint64_t div = ind >> 6 ; //quoziente della divisione
    uint64_t mod = ind & ((uint64_t) 0x3F); //modulo della divisione
    uint64_t mask = ((uint64_t) 1) << (63-mod);
    return (uint8_t)((A[div] & mask) >> (63-mod));
}





void printBitArray(uint64_t A[], uint64_t dim){
    
    uint64_t div = (dim-1) / 50 ; //quoziente della divisione
    
    uint64_t mod = (dim-1) % 50 ; //modulo della divisione    


    uint64_t index = 0;
    for(int i = 0; i < div; i++){
        for(int j = 0; j<50; j++){
            printf("%d", getBit(A, index));  index++;
            //printf("  ");
            }
        printf("\n");
        }
    
    //stampa dell'ultima riga'
    for(int j = 0; j<=mod; j++){
            printf("%d", getBit(A, index));  index++;
            //printf("  ");
        }
        printf("\n");
        

}

