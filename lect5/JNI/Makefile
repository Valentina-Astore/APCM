#Il nostro progetto è costituito dalla libreria nativa libarc4Lib.so (in linux) e dal programma in Java arc4PRNG.class
all: arc4PRNG.class libarc4Lib.so


arc4PRNG.class: arc4PRNG.java
	javac8 arc4PRNG.java 


#javah è un tool java che genera un file header ".h" a partire dal file sorgente in Java, quest'ultimo contenente la chiamata alle funzioni native
#In questo caso arcPRNG.h. Guardiamolo!

arcPRNG.h: arc4PRNG.java
	javah8 arc4PRNG



# Le due seguenti sono compilazioni standard di librerie. L'unica differenza sta nella opzione -fPIC
# Position independent code. Cioè la libreria potrà essere posizionata in ogni zona di memoria senza problemi.
# Vedi: https://stackoverflow.com/questions/5311515/gcc-fpic-optionhttps://stackoverflow.com/questions/5311515/gcc-fpic-option

arc4Lib.o: arc4Lib.c
	gcc -c -fPIC arc4Lib.c	

ByteLib.o:ByteLib.c
	gcc -c -fPIC ByteLib.c

# L'ultima chiamata a gcc crea "finalmente" la libreria nativa. Quella che in arcPRNG.java avevamo dichiarato.
# Questa chiamata dipende fortemente dal sistema in 2 aspeti.
# 1) Collocazione degli header file java per interfacciarsi a funzioni native. In linux sono jni.h e jni_md.h.
# Tramite il comando locate possiamo trovare le directory in cui sono posizionati. Ecco spiegate le opzioni -I.
# Ovviamente per versioni diverse di Java, S.O diversi o versioni diverse dello stesso S.O. Cambiano!!!
# (-fPIC),-z noexecstack, -shared sono necessarie per gcc sotto linux per creare una libreria dinamica e compatibile con le richeste di Java.
# In un MacBook air ad esempio non si usa -z noexecstack.
# Anche il nome della libreria jni che deve essere generata dipende dal sistema.
# Ad esempio in linux deve avere estensione ".so" e deve avere "lib" come prefisso (cfr. arcPRNG.java). Sul Mac deve avere estensione jnilib.

libarc4Lib.so: runarc4.c arc4Lib.o ByteLib.o 
	gcc -I/usr/lib/jvm/jdk1.8.0_202/include -I/usr/lib/jvm/jdk1.8.0_202/include/linux -fPIC -shared -z noexecstack\
		runarc4.c arc4Lib.o ByteLib.o -o  libarc4Lib.so

