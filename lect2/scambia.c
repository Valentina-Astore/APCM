#include <stdio.h>

void scambia(int *pa,int *pb);//lo star indica che indichiamo i puntatori e non il valore

int main() {
  int a,b;

  printf("a=");
  scanf("%d",&a);//ampersend & è l'operatore di referenziazione, cioè ci permette di indicare il puntatore di un dato oggetto
  printf("b=");
  scanf("%d",&b);
  // In scambia non passo il valore, ma l'indirizzo ad a e b.
  // L'indirizzo è ottenuto tramite l'operatore unario &(_), detto operatore di referenziazione.
  
  scambia(&a,&b);
  printf("Dopo lo scambio\n");
  printf("a=%d\n",a);
  printf("b=%d\n",b);
}



// Nella definizione della funzione ricevo due indirizzi ad int che sono pa e pb.
// D'altra parte io voglio accedere agli int puntati dall'indirizzo di a e b.
// Questo si ottiene con l'operarore di derefenziazione o indirezione *(_).
// In particolare pa=&a e pb=&b e a==*(&a), b==*(&b).
void scambia(int*  pa,int* pb){
  int c;
  c=*pa;
  *pa=*pb;
  *pb=c;  
}
// Ad esempio se volessi assegnare 
//
// int a,b=5;
// Invece di
// a=b;
// 
// potrei:
// int *pb;
// pb=&b;
// a=*pb;
// 

