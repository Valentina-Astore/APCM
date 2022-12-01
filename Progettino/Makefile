all: Client.class Server.class AES_CFB_DE AES_CFB_ED

Client.class: Client.java AES_CFB.class
	javac Client.java

Server.class: Server.java AES_CFB.class
	javac Server.java

AES_CFB.class: AES_CFB.java AEScLaunchThread.class
	javac AES_CFB.java
	
AEScLaunchThread.class: AEScLaunchThread.java
	javac AEScLaunchThread.java

AESTest: AESTest.c AES.Lib.o
	gcc AESTest.c -o AESTest AES.Lib.o
	
AES_CFB_DE: AES_CFB_DE.c AES.Lib.o
	gcc AES_CFB_DE.c -o AES_CFB_DE AES.Lib.o
	
AES_CFB_ED: AES_CFB_ED.c AES.Lib.o
	gcc AES_CFB_ED.c -o AES_CFB_ED AES.Lib.o

AES.Lib.o : AES.Lib.c AES.Lib.h
	gcc -c AES.Lib.c

