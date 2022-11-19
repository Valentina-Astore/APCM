
#define SIZE_ARR 1000000000
#include <stdlib.h>
#include <stdio.h>
int main() {
  long int i;

  static int array[SIZE_ARR];
  for(i=0;i<SIZE_ARR;i++)
    array[i]=i;

  for(i=0;i<SIZE_ARR;i++)
    printf("%d\n",array[i]);
  
}
