all: Client.class Server.class AES_CFB

Client.class: Client.java AES_CFB.class
	javac8 Client.java

Server.class: Server.java AES_CFB.class
	javac8 Server.java

AES_CFB.class: AES_CFB.java AEScLaunchThread.class
	javac8 AES_CFB.java
	
AEScLaunchThread.class: AEScLaunchThread.java
	javac8 AEScLaunchThread.java

AESTest: AESTest.c AES.Lib.o
	gcc AESTest.c -o AESTest AES.Lib.o
	
AES_CFB: AES_CFB.c AES.Lib.o
	gcc AES_CFB.c -o AES_CFB AES.Lib.o

AES.Lib.o : AES.Lib.c AES.Lib.h
	gcc -c AES.Lib.c

