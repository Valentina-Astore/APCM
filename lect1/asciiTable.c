#include <stdio.h>
int main() {
  int ch,col,row;
  ch=32;
  for(col=0;col<12;col++){
    printf("||");
    for(row=0;row<8;row++){
      if(ch<127){
	printf("%c|%3d||",ch,ch);
	ch++;
      } else printf(" |   ||");
    }
    printf("\n");
  }
}
