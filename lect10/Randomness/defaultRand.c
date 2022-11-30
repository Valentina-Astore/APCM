#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>



void main(){
  uint64_t p;
  int i;
  printf("RAND_MAX=%d\n\n", RAND_MAX);

  // In this way the function time returns an integer representing the actual time. Hence we have a little entropy...
  srand(time(NULL));

  printf(" Ten big pseudo-random maximal number :\n");
  for(i=0;i<10;i++){
    printf("%d: %d\n",i, rand());
  }

  printf(" 256 pseudo-random number between 0 and 255:"); 
  for(i=0;i<256;i++){
    if(i%16==0) printf("\n");
    printf("%03d ", rand()%256);
  }
  printf("\n");
}
