#include <stdlib.h>
#include <stdio.h>

// long long int hanno sicuramente 64 bit
// Il seguente è il costruttore del triangolo.

unsigned long long int * calculateTartaglia(int height);
// Ovviamente vogliamo anche visualizzarlo. 
void printTartaglia(unsigned long long int *T, int height);

int main(int argc, char *argv[]) {
  int height,level,i;
  unsigned long long int *T;
  if(argc==1){
    height=7;
  } else { 
    height=atoi(argv[1]);
  }
  // La funzione deve calcolare, ma anche allocare la memoria necessaria per contenere il triangolo.
  // In pratica è quello che in (C++) Java è il costruttore dell'oggetto.
  // In Java scriveremmo:
  // Tartaglia t=new Tartaglia(height);
  // Invece in C
  T=calculateTartaglia(height);
  // In Java scriveremmo
  // t.print(height);
  
  printTartaglia(T,height);

  // Decommentando abbiamo una seconda "istanza" dell'"oggetto" Tartaglia.
  // In questo modo posso simulare la creazione di oggetti come in Java o C++.
  /*
  unsigned long long int *T1;
  T1=calculateTartaglia(height+1);
  printTartaglia(T1,height+1);
  free(T1);
  */

  // Una volta finito l'uso del mio "oggetto" è importante deallocare la memoria.
  // Non siamo in Java!
  free(T);
  
}



