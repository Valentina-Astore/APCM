//#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include "bitArrLib.h"

void main(int argc, char *argv[]){
    uint64_t n = atoi(argv[1]);

    uint64_t* array = bitArray(n-1);
    
    //for (int i=0; i<n; i++){array[i]=(_Bool)0 ; }
    for (int i=2; i<= /*sqrt(n)*/ n; i++){
        int j = 2;
        while(j * i <= n){
     
            //array[i*j-1] = (_Bool) 1; 
            setBit(array, i*j - 2,1);
            j++;       
        }    
    }
    for (int i = 0; i<n-1; i++){   
        if(getBit(array,i) == 0){   printf("%d  " ,  i+2);   } 
    }

    free(array);

    printf("\n");
}   
