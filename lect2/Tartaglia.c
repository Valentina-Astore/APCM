#include <stdlib.h>
#include <stdio.h>

// long long int hanno sicuramente 64 bit
// Il seguente è il costruttore del triangolo.

unsigned long long int * calculateTartaglia(int height);
// Ovviamente vogliamo anche visualizzarlo. 
void printTartaglia(unsigned long long int *T, int height);

unsigned long long int getElt(unsigned long long int i, unsigned long long int j,  unsigned long long int* T );

void main(int argc, char *argv[]) {
  int height;
  unsigned long long int *T;
  if(argc==1){
    height=7;
  } else { 
    height=atoi(argv[1]);
  }

  T=calculateTartaglia(height);
  
  printTartaglia(T,height);

  free(T);
  
}



unsigned long long int * calculateTartaglia(int height){
  unsigned long long int length = height*(height+1)/2;
  unsigned long long int * T = malloc(sizeof(unsigned long long int)*(length+1));
  
  T[0]= (unsigned long long int) height;
  T[1]= (unsigned long long int) 1;
  T[2]= (unsigned long long int) 1;
  T[3]= (unsigned long long int) 1;
  T[4]= (unsigned long long int) 1;
  T[5]= (unsigned long long int) 2;
  
  unsigned long long int r, w;
  r = 3;  w = 6;
  unsigned long long int r1, r2;
  while (w < length){
    r1 = T[r]; r2 = T[r+1];
    if((r1==1)&&(r2==1)){
      T[w] = 1;
      w++;
      T[w] = 1;
      }  
    else{
      T[w]=r1+r2; 
      }
    r++; w++;
  }

  T[length]= (unsigned long long int) 1;

  return T;
  
}

unsigned long long int getElt(unsigned long long int i, unsigned long long int j,  unsigned long long int* T ){
  
  return T[(i*(i+1)/2) + j];
}


void printTartaglia(unsigned long long int *T, int height){

    unsigned long
 long int length = height*(height+1)/2;  
    
    int j = 1;
    int target = 1;  
    int p = 0;
    
    for (int k = 1; k<= height - target; k++){printf("    ");}
    
    for(int i=1; i <= length; i++){
    printf("%4lld ", T[i] ); printf("    ");
    if (j == target){
        printf("\n"); target++;
        for (int k = 1; k<= height - target; k++){printf("    ");}
        j = 1;        
        }
    else{j++;}
    
    } 
  }
