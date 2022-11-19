/*
 rispetto ad array.c uso malloc 
 Così  utilizzo lo heap che e' grande potenzialmente quanto l'intera RAM!
 Nel caso di allocazione dinamica di array invece si usa lo stack che e' uno 
 spazio statico utilizzabile dal programma ed e' limitato a pochi Megabyte.
 */


#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int size_arr,i;
  if(argc==1){
    size_arr=100;
  } else { 
    size_arr=atoi(argv[1]);
  }

  int *array;

  array=(int *)malloc(sizeof(int)*size_arr);//dobbiamo tenere conto della lunghezza dell'array ma anche della quantità di memoria necessaria per memorizzare ogni singolo elemento dell'array
  if(array==NULL) {
    printf("Memoria esaurita!\n");
    return(1);
  } else {
    for(i=0;i<size_arr;i++)
      array[i]=i;

    free(array);// dopo aver fatto malloc bisogna poi liberare la memoria!
    //    for(i=0;i<size_arr;i++)
    //  printf("%d\n",array[i]);
  }
  
}
