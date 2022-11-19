/*
- Nuova direttiva di preprocessore
define

- int
- Stringa 
array di char

Altra funzione in stdio.h: scanf
 */
#include <stdio.h>
#define ANNO 2022
#define MAXNOME 20
int main() {
  int anno_nascita;
  char nome[MAXNOME];

  printf("Dammi il tuo nome: ");
  scanf("%s",nome);
  printf("Ciao %s\n",nome);//printf("Ciao %s\n",&nomee[0]);

  printf("Qual'è il tuo anno di nascita (4 cifre)? ");
 
  scanf("%d",&anno_nascita);
 

  printf("%s hai %d hanni, o ci sei vicino/a!\n",nome, ANNO - anno_nascita);
}
