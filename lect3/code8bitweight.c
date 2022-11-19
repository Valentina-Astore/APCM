#include <inttypes.h>

#include <stdlib.h>
#include <stdio.h>

#include "ByteLib.h"  

void main(void)
    {
    uint8_t w1; uint8_t w2; uint8_t w3;
    printf("Insert a word :");
    scanf("%" SCNu8, &w1);
    printf("Insert a word :");
    scanf("%" SCNu8, &w2);
    printf("Insert a word :");
    scanf("%" SCNu8, &w3);    
    
    for(uint8_t i1 = 0; i1< 2; i1++){
        for(uint8_t i2 =0; i2<2; i2++){
            for(uint8_t i3 =0; i3<2; i3++){
                    uint8_t word = (i1*w1)^(i2*w2)^(i3*w3);
                    print8bit(word);
                    printf("  with weight %d \n", Hw(word));                
                }        
        }    
    }
    


}
