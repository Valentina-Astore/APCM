all: PrimeTest BBSRandByte

PrimeTest: PrimeTest.c PrimeLib.o
	gcc PrimeTest.c -o PrimeTest PrimeLib.o -lgmp 

BBSRandByte: BBSRandByte.c PrimeLib.o BBSLib.o
	gcc BBSRandByte.c -o BBSRandByte PrimeLib.o BBSLib.o -lgmp 

PrimeLib.o: PrimeLib.c
	gcc -c PrimeLib.c 

BBSLib.o: BBSLib.c
	gcc -c BBSLib.c 
