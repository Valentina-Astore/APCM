#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
    int n = atoi(argv[1]);

    _Bool* array;
    array = (_Bool *) malloc(sizeof(_Bool)*n);
    for (int i=0; i<n; i++){array[i]=(_Bool)0 ; }
    for (int i=2; i<=n; i++){
        int j = 2;
        while(j * i <= n){
     
            array[i*j-1] = (_Bool) 1; 
            j++;       
        }    
    }
    for (int i = 1; i<n; i++){   
        if(array[i] == 0){   printf("%d  " ,  i+1);   } 
    }

    free(array);

    printf("\n");
}   
