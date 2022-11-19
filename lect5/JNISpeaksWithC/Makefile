all: arc4PRNG.class arc4JNI.class libarc4Lib.so

arc4PRNG.class: arc4PRNG.java
	javac8 arc4PRNG.java 

arc4JNI.class: arc4JNI.java
	javac8 arc4JNI.java 	


arc4JNI.h: arc4JNI.java
	javah8 arc4JNI

arc4Lib.o: arc4Lib.c
	gcc -c -fPIC arc4Lib.c	

libarc4Lib.so: PRNG.c arc4Lib.o arc4JNI.h
	gcc -I/usr/lib/jvm/jdk1.8.0_202/include -I/usr/lib/jvm/jdk1.8.0_202/include/linux -fPIC -shared -z noexecstack\
		PRNG.c arc4Lib.o -o  libarc4Lib.so



