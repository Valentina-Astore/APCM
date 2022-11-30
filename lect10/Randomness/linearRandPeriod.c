#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t pow2(int k){
  uint64_t res=1;
  return (res << k);
}

uint64_t periodLengthLinear(uint64_t X, uint64_t m, uint64_t a, uint64_t b){
  uint64_t x,y;
  uint64_t k=0,j,r=1;

  y=X;
  do{
    r+=r;
    x=y;
    j=k;
    do{
      k++;
      y=(a*y+b)%m;
    }while(x!=y && k<r);
  } while(x!=y);
  return k-j;
}


void main(){
  int k=31;
  uint64_t X,m,a,b,p,i;
  printf("RAND_MAX=%d\n", RAND_MAX);
  b=12345;
  a=1103515245;
  m=pow2(k);

  X=0;
  p=periodLengthLinear(X,m,a,b);
  printf("Period x_k=ax_k+b mod m: %"PRIu64"\n",p);


}
