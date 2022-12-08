#all : PrimeTest
all : GenKey

PrimeTest : PrimeTest.c PrimeLib.o
	gcc PrimeTest.c -o PrimeTest PrimeLib.o -lgmp -I/opt/local/include -L/opt/local/lib

GenKey : GenKey.c PrimeLib.o RSA.Lib.o
	gcc GenKey.c -o GenKey PrimeLib.o RSA.Lib.o -lgmp -I/opt/local/include -L/opt/local/lib


GenKeyOnFile : GenKeyOnFile.c PrimeLib.o RSA.Lib.o
	gcc GenKeyOnFile.c -o GenKeyOnFile PrimeLib.o RSA.Lib.o -lgmp -I/opt/local/include -L/opt/local/lib

Bob : Bob.c PrimeLib.o RSA.Lib.o
	gcc Bob.c -o Bob PrimeLib.o RSA.Lib.o -lgmp -I/opt/local/include -L/opt/local/lib

Alice : Alice.c PrimeLib.o RSA.Lib.o
	gcc Alice.c -o Alice PrimeLib.o RSA.Lib.o -lgmp -I/opt/local/include -L/opt/local/lib


AliceCRT : AliceCRT.c PrimeLib.o RSA.Lib.o
	gcc AliceCRT.c -o AliceCRT PrimeLib.o RSA.Lib.o -lgmp -I/opt/local/include -L/opt/local/lib


PrimeLib.o : PrimeLib.c PrimeLib.h
	gcc -c PrimeLib.c -I/opt/local/include 

RSA.Lib.o : RSA.Lib.c RSA.Lib.h
	gcc -c RSA.Lib.c -I/opt/local/include

