#include <stdio.h>
int max=10;//variabile globale nota a tutte le funzioni. Se non la si vuole utilizzare si può usare define in precompilazione

void ruotaVett(int *pVett,int len);//signature delle funzioni che costruirò più tardi
void printVett(int *pVett,int len);

int main() {
  int i,Vett[max];
  // Inizializzo il vettore con i valori (0,1,...,max-1)
  for(i=0;i<max;i++) Vett[i]=i;
  //

  // Ruoto un passo alla volta il vettore e lo visualizzo max+1 volte
  for(i=0;i<=max;i++){
    printVett(Vett,max);
    ruotaVett(Vett,max);
   }
  //
}

// Nella seguente funzione uso l'aritmetica dei puntatori
void ruotaVett(int *pV,int len){
  int c=*pV;// Come in scambia.c devo salvare il primo valore!
  for(int i=0;i<len-1;i++){
    // L'aritmetica dei puntatori permette tramite la somma pV+i di saltare all'indirizzo di memoria RAM in funzione del tipo.
    // Quindi pV e (pV+i) non distano i bytes ma i*(lunghezza in bytes di un int) 
    *(pV+i)=*(pV+i+1);//Ecco un esempio.
    // Potevamo fare anche
    // pV[i]=pV[i+1])
  }
  // Alla fine pongo pV[len-1]=c
  *(pV+len-1)=c;
}


// A questo punto capire printVett è un facile esercizio!
void printVett(int *pV,int len){
  printf("(");
   for(int i=0;i<len;i++){   
     printf("%d",*(pV+i));
    // All'interno di printf c'è un if inline
    //(cond)? retTrue : retFalse 
    // retTrue/retFalse può essere qualsiasi tipo (int/char/array  o strutture);
    printf((i==len-1) ? ")" : ",");
  }
  printf("\n");
}
//
