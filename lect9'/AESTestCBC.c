/*

 */
#include <stdio.h>
#include <inttypes.h>
#include "./AES.Lib.h"

int main(){
  int i,j,k;
  uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]=
    {{0x2b,0x7e,0x15,0x16},
     {0x28,0xae,0xd2,0xa6},
     {0xab,0xf7,0x15,0x88},
     {0x09,0xcf,0x4f,0x3c}};

  uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
  uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
		    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
		    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
		    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10 };
    

  uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD];
  roundKeyGen(roundKey,Key);

  printf("Round Key generated.\n");
  for(i=0;i<=NR_ROUNDS;i++) {
    for(j=0;j<WORDS_IN_KEY;j++){
      for(k=0;k<BYTES_IN_WORD;k++){
	printf("%02X ", roundKey[i][j][k]);
      }
      printf("    ");
    }
    printf("\n");
  }

  printf("\nIv:\n");
  for(i=0;i<BLOCK_SIZE;i++){
    printf("%02X ", iv[i]);
  }
  printf("\n");

  printf("\nInput:");
  for(i=0;i<64;i++) {
    if(i%16==0) printf("\n");
    printf("%02X ", in[i]);
    printf(" ");
  }

  printf("\n");
  encryptCBC(in,64, roundKey, iv);
  
  printf("\nOutput:");
  for(i=0;i<64;i++) {
    if(i%16==0) printf("\n");
    //    print8bit(in[i]);
    printf("%02X", in[i]);
    printf(" ");
  }
        
  printf("\n");

}


