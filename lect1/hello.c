/* 
- Compilazione in gcc
gcc hello.c -o hello
- Esecuzione da Terminale
./hello
- Funzioni di I/O
In stdio.h sono presenti tutti i prototipi (dette firme/signature in Java) delle funzioni di I/O definite nello standard ANSI.
Ad esempio printf.
Un proptotipo non e' altro che la definizione di una funzione "privata del suo contenuto".
A esempio il proptotipo di una funzione che somma a e b e restituisce la somma sara':

int somma(int a,int b);

 
printf e \n
- Tutto in c è una funzione!!
Ad es. qui abbiamo due funzioni: main() e printf()
- Blocchi e righe 
{} e ;
*/
#include <stdio.h>
int main() {
  printf("Ciao mondo\n");
}
