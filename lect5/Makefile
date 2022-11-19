#Questo è un commento del Makefile (forse nella prima riga sarà da cambiare qualcosa)

all: arc4Crypt arc4Decrypt arc4Setup arc4PRNG


arc4Crypt: arc4Crypt.c arc4Lib.o ByteLib.o
	gcc arc4Crypt.c arc4Lib.o ByteLib.o -o arc4Crypt

arc4Decrypt: arc4Decrypt.c arc4Lib.o ByteLib.o
	gcc arc4Decrypt.c arc4Lib.o ByteLib.o -o arc4Decrypt

arc4Setup: arc4Setup.c arc4Lib.o ByteLib.o
	gcc arc4Setup.c arc4Lib.o ByteLib.o -o arc4Setup

arc4PRNG: arc4PRNG.c arc4Lib.o ByteLib.o
	gcc arc4PRNG.c arc4Lib.o ByteLib.o -o arc4PRNG

ByteLib.o : ByteLib.c ByteLib.h
	gcc -c ByteLib.c

arc4Lib.o : arc4Lib.c arc4Lib.h
	gcc -c arc4Lib.c

