#include "stdio.h"
void main(){
    char p[]="Hello CryptoLabTN"; //scrivo come array di caratteri il testo da invertire
    char c;
    int size = sizeof(p);
    for (int i = 0; i<(size / 2); i++){
        c = *(p+i);
        *(p+i) = *(p+size-1-i);
        *(p+size-1-i) = c;     
    }
    for (int i= 0; i< size; i++){
    printf("%c",p[i]);    
    }
    printf("\n");
}
