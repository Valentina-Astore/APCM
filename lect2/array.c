#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int size_arr,i;
  if(argc==1){
    size_arr=100;
  } else { 
    size_arr=atoi(argv[1]);
  }

  int array[size_arr];
  for(i=0;i<size_arr;i++)
    array[i]=i;

  for(i=0;i<size_arr;i++)
    printf("%d\n",array[i]);
  
}
