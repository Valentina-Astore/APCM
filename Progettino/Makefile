all: AESTest

AESTest: AESTest.c AES.Lib.o
	gcc AESTest.c -o AESTest AES.Lib.o

AES.Lib.o : AES.Lib.c AES.Lib.h
	gcc -c AES.Lib.c

