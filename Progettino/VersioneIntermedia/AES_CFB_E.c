#include <stdint.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

#include "AES.Lib.h"

int main(int argc, char *argv[]) {

    uint8_t Key[WORDS_IN_KEY][BYTES_IN_WORD]= {{0x2b,0x7e,0x15,0x16},  {0x28,0xae,0xd2,0xa6},  {0xab,0xf7,0x15,0x88},  {0x09,0xcf,0x4f,0x3c}};
    uint8_t roundKey[NR_ROUNDS+1][WORDS_IN_KEY][BYTES_IN_WORD];
    roundKeyGen(roundKey,Key);

	int fpIn;
	int fpOut;
	 
	char id[7];   
	char fileNameOut[] = "C2JavaEgvgvgv";
	char fileNameIn[]= "Java2CEgvgvgv";
	    
	if(argc!=2){
		printf("%s id\n", argv[0]);
		return 1;
	} else {    
		strcpy(id, argv[1]);
		sprintf(fileNameIn ,"Java2CE%s", id);
		sprintf(fileNameOut,"C2JavaE%s", id);
    }

    fpIn = open(fileNameIn,O_RDONLY);
	fpOut = open(fileNameOut,O_WRONLY);
	
	
	//Lettura del testo da cifrare e decifratura
	uint8_t inlength;
	do {
		
	    read(fpIn, &inlength, 1);   //Lettura lunghezza del testo
		    
		//Lettura del testo ricevuto da Java
	    uint8_t buf[inlength];
	    if(inlength>0){
		    for(int i=0;i<inlength;i++) {
		        read(fpIn, buf+i, 1);
		    }

            //Cifratura del testo
		    encryptCFB(buf, inlength, roundKey);
	      
	        //Invio del contenuto cifrato a Java
		    write(fpOut,buf,inlength);
	    }
	
	} while(inlength!=0);
	  
	close(fpOut);
	close(fpIn); 
	return 0;
}
