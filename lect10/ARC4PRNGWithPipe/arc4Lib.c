#include <stdio.h>
#include <stdint.h>
#include "arc4Lib.h"

// In questa nuova versione ho NRMAXARC4 stati indipendenti. Tanti quanto il numero massimo di sessioni arc4 eseguibili

struct {
 uint8_t state[256];
 uint8_t i,j;
} S[NRMAXARC4];


// Scambia a e b.
void swap(uint8_t *a, uint8_t *b){
  uint8_t c=*a;
  *a=*b;
  *b=c;
}
//

// Calcola il valore iniziale dell'array state in funzione della chiave.

void arc4Setup(int id,const uint8_t key[], uint8_t len) {
  int i;
  uint8_t j;
  
  for (i = 0; i < 256; ++i) S[id].state[i] = i;
  j=0;
  for (i = 0; i < 256; ++i) {
    j =(uint8_t)(j + S[id].state[i] + key[i % len]);
    // il seguente comando commentato 
    // swap(&(S[id].state[i]),&(S[id].state[j]));
    // è equivalente a 
    swap(&S[id].state[i],&S[id].state[j]);
    // Infatti gli operatori . e [] hanno precedenza rispetto a &
  }
}
//


// Genera nel vettore out di lunghezza almeno len, e tramite il vettore state
// già inizializzato tramite arc4Setup, un insieme di byte pseudo random.
void arc4KeyStream(int id,uint8_t out[], uint64_t len) {

  uint8_t *i,*j;
  uint64_t k;
  for (k = 0; k < len; k++)  {
    i=&(S[id].i);
    j=&(S[id].j);

    // Qui la parentesi è fondamentale. Infatti l'operatore ++ precede l'operatore *. 
    (*i)++;
    // Qui non è necessaria perchè l'operatore += segue nell'ordine l'operatore *. 
    (*j)+=S[id].state[*i];
    swap(&(S[id].state[*i]),&(S[id].state[*j]));
    out[k] = S[id].state[(uint8_t)(S[id].state[*i] + S[id].state[*j])];

  }
}


// Stampa lo State attuale.
void arc4PrintState(int id) {
  int i;
  for(i=0;i<256;i++){
    printf("%02X.",S[id].state[i]);
    if((i+1)%16==0) printf("\n");
  }
}
//
