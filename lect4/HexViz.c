/*
 getchar() prende un char da stdin fino a che inserisco un EOF. In Unix Ctrl+D.
 Osserviamo il comportamento con <Invio>, <Tab> e le lettere accentate.
 Si può anche reindirizzare lo stdin da file:
 ./HezViz < testo.txt
*/

#include <stdio.h>
int main(){
  int c;
  while((c=getchar())!=EOF){
    if(c>=32 && c<=126)
      printf("%c %2X\n",c,c);
    else
      printf("  %2X\n",c);
  }
}


