#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "arc4Lib.h"
// Il seguente è il file autogenerato tramite il comando
// javah arc4JNI
#include "arc4JNI.h"
// Il nome delle funzioni (protocolli/firme)
// sono presi da arc4PRNG.h

// (JNIEnv *env, jobject obj, ...) Sono spiegati anche sul file JNI.pdf che trovate in Reference (Chap. 3)
JNIEXPORT void JNICALL
Java_arc4JNI_Setup(JNIEnv *env, jobject obj, jbyteArray keyin){
  //Mi da la lunghezza degli array passati per parametro  
  jsize keylength=(*env)->GetArrayLength(env,keyin);
  // Ne crea una copia utilizzabile da C
  jbyte *key=(*env)->GetByteArrayElements(env,keyin,0);

  //Chiamo finalmente la funzione che configura internamente lo state
  arc4Setup(key, keylength);
  // Libera la memoria dell'array di supporto...
  // Nota: Il garbage collector di Java non funziona con gli array generati nelle funzioni native. Ad es. tramite GetByteArrayElements(...)
  // Dunque dovrò esplicitamente rilasciare la memoria.
  (*env)->ReleaseByteArrayElements(env, keyin, key, 0);
  return;
}

JNIEXPORT void JNICALL
Java_arc4JNI_PRNG(JNIEnv *env, jobject obj, jbyteArray Out){
  //Mi da la lunghezza degli array passati per parametro  
  jsize outlength=(*env)->GetArrayLength(env,Out);
  // Ne crea una copia utilizzabile da C
  jbyte *out=(*env)->GetByteArrayElements(env,Out,0);
  //
  
  arc4KeyStream(out, outlength);

  // Libera la memoria degli array di supporto...
  // ...e se ci sono delle modifiche come nella riga successiva aggiorna l'array passato come parametro.
  // Se non faccio questo passo non modifico l'array della funzione chiamante!!!
  (*env)->ReleaseByteArrayElements(env, Out, out, 0);
  return;
}

