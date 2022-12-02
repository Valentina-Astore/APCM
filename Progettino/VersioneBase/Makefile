all: Client.class Server.class AES_CFB_D AES_CFB_E

Client.class: Client.java AES_CFB_D.class AES_CFB_E.class
	javac8 Client.java

Server.class: Server.java AES_CFB_D.class AES_CFB_E.class
	javac8 Server.java

AES_CFB_D.class: AES_CFB_D.java
	javac8 AES_CFB_D.java
	
AES_CFB_E.class: AES_CFB_E.java
	javac8 AES_CFB_E.java
	
AEScLaunchThread.class: AEScLaunchThread.java
	javac8 AEScLaunchThread.java

AESTest: AESTest.c AES.Lib.o
	gcc AESTest.c -o AESTest AES.Lib.o
	
AES_CFB_D: AES_CFB_D.c AES.Lib.o
	gcc AES_CFB_D.c -o AES_CFB_D AES.Lib.o
	
AES_CFB_E: AES_CFB_E.c AES.Lib.o
	gcc AES_CFB_E.c -o AES_CFB_E AES.Lib.o

AES.Lib.o : AES.Lib.c AES.Lib.h
	gcc -c AES.Lib.c

