#include <inttypes.h>

uint32_t parity(uint32_t x){
    //working on 16 bits
    uint32_t mask = 0x0000FFFF
    uint32_t temp_1 = x ^ mask
    uint32_t temp_2 =( x >> 16) ^ mask
    uint32_t temp = temp_1 ^temp_2

    //working on 8 bits
    mask = 0x000000FF
    temp_1 = temp ^ mask
    temp_2 =( temp >> 8) ^ mask
    temp = temp_1 ^ temp_2

    //working on 4 bits
    mask = 0x0000000F
    temp_1 = temp ^ mask
    temp_2 =( temp >> 4) ^ mask
    temp = temp_1 ^ temp_2

    //working on 2 bits
    mask = 0x00000003
    temp_1 = temp ^ mask
    temp_2 =( temp >> 2) ^ mask
    temp = temp_1 ^ temp_2
    
    mask = 0x00000001
    temp_1 = temp ^ mask
    temp_2 =( temp >> 2) ^ mask
    temp = temp_1 ^ temp_2

    return temp
    }


void setupRegisters(){
    
}
  uint32_t mask;
  uint8_t clockbit;
  uint32_t feedbackbits;
  uint8_t out;
    









    }

