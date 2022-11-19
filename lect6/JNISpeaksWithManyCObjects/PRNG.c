#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "arc4Lib.h"

#include "arc4JNI.h"
JNIEXPORT void JNICALL
Java_arc4JNI_Setup(JNIEnv *env, jobject obj, jbyteArray keyin){

  jsize keylength=(*env)->GetArrayLength(env,keyin);
  jbyte *key=(*env)->GetByteArrayElements(env,keyin,0);


  // Devo acquisire il campo id dell'oggetto arc4.
  // Questo andrà in jint (vedi jint in jni_md.h)
  // jint->int
  jint jid;
  

  // Chap.4 di JNI.pdf.
  // Definisco l'identificatore di un generico campo. Nota : Non deve portare confusione il nome; infatti fid non ha niente a che fare con jid.
  // In java ogni campo di una classe ha un proprio identificatore.
  jfieldID fid; /* store the field ID */
  
  //Calcolo il puntatore alla classe: Qui ho bisogno dell'oggetto chiamante -->obj
  jclass cls = (*env)->GetObjectClass(env, obj);
  //... e al campo id. Il descrittore di un intero è semplicemente "I" (cfr. pg.43 dove invece ho un oggetto stringa)
  fid = (*env)->GetFieldID(env, cls, "id","I");
  if (fid == NULL) {
    return; /* failed to find the field */
  };

  // Finalmente posso ottenere il "mio" id...
  jid = (*env)->GetIntField(env, obj, fid);
  // ...e lo stampo per sicurezza!!
  //printf("Id=%d\n",jid);
  //



  arc4Setup(jid, key, keylength);
  (*env)->ReleaseByteArrayElements(env, keyin, key, 0);
  return;
}

JNIEXPORT void JNICALL
Java_arc4JNI_PRNG(JNIEnv *env, jobject obj, jbyteArray Out){
  jsize outlength=(*env)->GetArrayLength(env,Out);
  jbyte *out=(*env)->GetByteArrayElements(env,Out,0);


  //Lo stesso faccio qui. Senza stampare ormai ci credo!
  jint jid;
  jfieldID fid;
  jclass cls = (*env)->GetObjectClass(env, obj);
  fid = (*env)->GetFieldID(env, cls, "id","I");
  if (fid == NULL) {
    return; /* failed to find the field */
  };
  jid = (*env)->GetIntField(env, obj, fid);

  
  arc4KeyStream(jid,out, outlength);

  (*env)->ReleaseByteArrayElements(env, Out, out, 0);
  return;
}

