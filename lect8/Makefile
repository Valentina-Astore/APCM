#all: AESKeySched AESTest AESSimply AESTestCBC AESMult256 AESPow256 AESxtime
all: AESKeySched

AESKeySched: AESKeySched.c AES.Lib.o
	gcc AESKeySched.c -o AESKeySched AES.Lib.o


AESSimply: AESSimply.c AES.Lib.o
	gcc AESSimply.c -o AESSimply AES.Lib.o

AESMult256: AESMult256.c AES.Lib.o
	gcc AESMult256.c -o AESMult256 AES.Lib.o

AESPow256: AESPow256.c AES.Lib.o
	gcc AESPow256.c -o AESPow256 AES.Lib.o

AESxtime: AESxtime.c AES.Lib.o
	gcc AESxtime.c -o AESxtime AES.Lib.o

AESTest: AESTest.c AES.Lib.o
	gcc AESTest.c -o AESTest AES.Lib.o

AESTestCBC: AESTestCBC.c AES.Lib.o
	gcc AESTestCBC.c -o AESTestCBC AES.Lib.o

AES.Lib.o : AES.Lib.c AES.Lib.h
	gcc -c AES.Lib.c

