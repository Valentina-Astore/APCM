#include "stdio.h"
void main(){
  char *pt1="Hello CryptoLabTN"; /* eax. Qui utilizziamo *p che "punta ad" un indirizzo di memoria p che contiene un char, un carattere (ASCII).
				    Lo spiegheremo meglio nelle prossime lezioni. */
  char *pt2;                     //ebx
  pt2=pt1;                // ebx=eax
  printf("%s\n",pt2);     //La stampa viene tradotto a seconda del SO mediante la libreria "stdio". Grazie Ritchie! Se gira su Linux Intel userà int 80h ad esempio. Ma noi ci disinteressiamo della cosa...
  // nextchar
  while(*pt1!='\0'){      //jz  
    pt1++;                //inc
  }                       //jmp nextchar
  // finished
  printf("%d\n",(int)(pt1-pt2)); //sub
}
