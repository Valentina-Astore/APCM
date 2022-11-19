all: LFSR #A5.1.PRNG A5.1.Crypt A5.1.Decrypt KeySetup Majority


A5.1.Crypt: A5.1.Crypt.c A5.1.Lib.o
	gcc A5.1.Crypt.c -o A5.1.Crypt A5.1.Lib.o	


A5.1.Decrypt: A5.1.Decrypt.c A5.1.Lib.o
	gcc A5.1.Decrypt.c -o A5.1.Decrypt A5.1.Lib.o	

A5.1.PRNG: A5.1.PRNG.c A5.1.Lib.o
	gcc A5.1.PRNG.c -o A5.1.PRNG A5.1.Lib.o

KeySetup: KeySetup.c A5.1.Lib.o
	gcc KeySetup.c -o KeySetup A5.1.Lib.o

#Majority: Majority.c A5.1.Lib.o
	gcc Majority.c -o Majority A5.1.Lib.o

LFSR : LFSR.c A5.1.Lib.o
	gcc LFSR.c -o LFSR A5.1.Lib.o

A5.1.Lib.o : A5.1.Lib.c A5.1.Lib.h
	gcc -c A5.1.Lib.c

