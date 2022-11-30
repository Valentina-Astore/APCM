#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

uint64_t pow2(int k){
  uint64_t res=1;
  return (res << k);
}

void main(){
  int k=31;
  uint64_t X,m,a,b,p,i;
  printf("RAND_MAX=%d\n", RAND_MAX);
  b=12345;
  a=1103515245;
  m=pow2(k);
  printf("x=ax+b mod m ===>x=%"PRIu64"x +%"PRIu64" mod %"PRIu64"\n",a,b,m);


  X=0;
  for(i=0;i<=10;i++){
    X=(a*X+b)%m;
    printf("%"PRIu64": %"PRIu64"\n",i,X);
  }
}
