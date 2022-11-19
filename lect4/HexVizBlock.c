/*
SPIEGAZIONE FREAD (non del main)
 In questo caso usiamo fread che legge un numero di "oggeti" di data dimensione:
 1) Restituisce il numero di oggetti effettivamente letti;
 2) Il primo parametro indica il buffer sul quale memorizzare gli oggetti letti;
 3) Il II indica la dimensione dell'oggetto;
 4) Il III indica il numero di oggetti da leggere (se ce ne sono abbastanza, altrimenti legge i rimanenti e dice quanti sono in nread);
 5) Il IV indica il puntatore al file aperto.
*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define MAXBUF 16
int main(int argc, char *argv[]){
  uint8_t bufin[MAXBUF];
  int i,nread;
  char filein[80];
  FILE *fpin;
  
  if(argc!=2){
    printf("%s filein\n", argv[0]);
    return 0;
  } else {
    strcpy(filein,argv[1]);//copia il nome del file da cui vogliamo leggere (passato in input da tastiera) alla stringa a cui punta filein 
  }
  fpin=fopen(filein,"r");//fopen prende in input un puntatore (filein) e ritorna un puntatore(fpin)

  do {
    // Leggi da fpin il blocco di  MAXBUF oggetti (ognuno di dimensione sizeof(oggetto))  e posizionalo in bufin.
    // se ne leggi meno di MAXBUF dimmelo in nread!
    nread=fread(bufin, sizeof( uint8_t ), MAXBUF, fpin);
    for(i=0;i<nread;i++)
       printf("%02X ",bufin[i]);

    if(nread<MAXBUF)
      for(int j=i;j<MAXBUF;j++) printf("   ");
      
    for(i=0;i<nread;i++)
      if(bufin[i]>=32 && bufin[i]<=126)
	printf("%c",bufin[i]);
      else
        printf(".");
  
    printf("\n");
  } while(nread==MAXBUF); // Se nread<MAXBUF ho letto l'intero file.
  fclose(fpin);
}
