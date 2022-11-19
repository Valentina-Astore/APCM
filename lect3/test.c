
#include "bitArrLib.h"


void main(){

 uint64_t* c = bitArray(72);
 setBit(c, 1, 1);
 setBit(c, 2, 1);
 setBit(c, 51, 1);
 setBit(c, 52, 1);
 //setBit(c, 1, 0);
 printBitArray(c,72);
 printf("%"PRIu8,getBit(c,0));
 printf(" %"PRIu8,getBit(c,1));
 printf(" %"PRIu8"\n",getBit(c,2));
 
 free(c);
}
