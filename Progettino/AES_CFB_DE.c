#include <stdint.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "AES.Lib.h"
//#include "AESStuff.c"


int main(int argc, char *argv[]) {

//    printf("uehi!");

  uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]= {{0x2b,0x7e,0x15,0x16},  {0x28,0xae,0xd2,0xa6},  {0xab,0xf7,0x15,0x88},  {0x09,0xcf,0x4f,0x3c}};

  int fpIn;
  int fpOut;
  
  char id[7];   
  char fileNameOut[] = "C2Javagvgvgv";
  char fileNameIn[]= "Java2Cgvgvgv";
  
  uint8_t inlength;
  
  
  if(argc!=2){
    printf("%s id\n", argv[0]);
    return 1;
  } else {    
    //printf("STAMPA UNO %s\n", fileNameIn);
    strcpy(id, argv[1]);
    
    
    //sprintf crea la stringa in fileNameIn/Out, e si comporta in modo analogo a printf
    sprintf(fileNameIn ,"Java2C%s", id);
    sprintf(fileNameOut,"C2Java%s", id);
    
    
  }
  
  uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD];
  roundKeyGen(roundKey,Key);


//  DECRYPTION
  
  fpIn=open(fileNameIn,O_RDONLY);
  fpOut=open(fileNameOut,O_WRONLY);
  
  
  do {
    
    read(fpIn, &inlength, 1);
    
    uint8_t buf[inlength];
    
    if(inlength>0){
      for(int i=0;i<inlength;i++) {
          read(fpIn, buf+i, 1);
      }

      decryptCFB(buf, inlength, roundKey);
  
      write(fpOut,buf,inlength);
    }

  } while(inlength!=0); //altrimenti esco


  close(fpOut);
  close(fpIn); 

//  ENCRYPTION

  printf("sono ancora vivo");

  fpIn=open(fileNameIn,O_RDONLY);
  fpOut=open(fileNameOut,O_WRONLY);
  
  
  do {
    
    read(fpIn, &inlength, 1);
    printf("\nValeSprota --> %d\n", inlength);
    
    uint8_t buf[inlength];
    
    if(inlength>0){
      for(int i=0;i<inlength;i++) {
          read(fpIn, buf+i, 1);
      }

      encryptCFB(buf, inlength, roundKey);
  
      write(fpOut,buf,inlength); printf("Valore inviato %"PRIu8"", buf[0]);
    }

  } while(inlength!=0); //altrimenti esco
  
  close(fpOut);
  close(fpIn); 
  return 0;
}
