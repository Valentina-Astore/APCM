import java.util.Random;
import java.io.*;
import java.net.*;

public class RandomThreadServer implements Runnable {
    static ServerSocket serverSocket;
    arc4 arc4;

    public static void PrintOut(byte[] Out){
	System.out.println("----");
	for(int i=0;i<Out.length;i++)
	    System.out.print(String.format("%02X",Out[i]));
	System.out.println();
    }

    public void run(){
	String threadName=Thread.currentThread().getName();
	// non serve a niente
	byte Key[]={'p','i','p','p','o'};
	//
	byte random[];
	random=new byte [16];
	arc4=new arc4();
	// Integer.parseInt(threadName)
	arc4.Setup(Key,Integer.parseInt(threadName));

	
	try {
	    
	    Socket s=serverSocket.accept();
	    DataOutputStream writer=new DataOutputStream(s.getOutputStream());

	    for(int i=0;i<30000;i++){
		arc4.PRNG(random);
		
		System.out.println(threadName+")");
		PrintOut(random);
		for(int j=0;j<16;j++)
		    writer.writeByte(random[j]);

	    }
	    writer.close();
	} catch(IOException ex){
	    ex.printStackTrace();
	} finally {
	    //Questo è nuovo!!!!!
	    arc4.close();
	    //
	}
    }
    
    public static void main(String[] args){
	try {
	    serverSocket=new ServerSocket(2022);
	    RandomThreadServer r1=new RandomThreadServer();
	    RandomThreadServer r2=new RandomThreadServer();
	    RandomThreadServer r3=new RandomThreadServer();
	    RandomThreadServer r4=new RandomThreadServer();

	    // Dato che gli oggetti r1,...,r4 sono tutti degli oggetti runnable posso creare 4 distinti threads
	    Thread t1=new Thread(r1);
	    Thread t2=new Thread(r2);
	    Thread t3=new Thread(r3);
	    Thread t4=new Thread(r4);
	    //
	    // Gli do dei nomi 
	    t1.setName("1");
	    t2.setName("2");
	    t3.setName("3");
	    t4.setName("4");
	    // ... e li lancio. A questo punto il metodo run viene lanciato per ognuno dei 4 nuovi thread. Ognuno col suo stack.
	
	    t1.start();
	    t2.start();
	    t3.start();
	    t4.start();
	} catch(IOException ex){
	    ex.printStackTrace();
	}
    }
}
