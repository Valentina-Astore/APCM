all: RandomThreadServer.class RandomThreadClient.class arc4.class PRNG PRNGTest PRNGTest2

RandomThreadServer.class: RandomThreadServer.java arc4.class
	javac RandomThreadServer.java

RandomThreadClient.class: RandomThreadClient.java
	javac RandomThreadClient.java

arc4.class: arc4.java
	javac arc4.java 	


arc4Lib.o: arc4Lib.c
	gcc -c -fPIC arc4Lib.c	


PRNG : PRNG.c arc4Lib.o 
	gcc PRNG.c arc4Lib.o -o PRNG


PRNGTest : PRNGTest.c
	gcc PRNGTest.c -o PRNGTest

PRNGTest2 : PRNGTest2.c
	gcc PRNGTest2.c -o PRNGTest2
