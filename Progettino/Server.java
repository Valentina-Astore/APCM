import java.util.Random;
import java.io.*;
import java.net.*;



public class Server /*implements Runnable */{
    static int i; static int j;


//    public void run(){
//	String threadName=Thread.currentThread().getName();
//	// non serve a niente
//	byte Key[]={'p','i','p','p','o'};
//	//
//	byte random[];
//	random=new byte [16];
//	arc4=new arc4();
//	// Integer.parseInt(threadName)
//	arc4.Setup(Key,Integer.parseInt(threadName));
//
//	
//	try {
//	    
//	    Socket s=serverSocket.accept();
//	    DataOutputStream writer=new DataOutputStream(s.getOutputStream());
//
//	    for(int i=0;i<30000;i++){
//		arc4.PRNG(random);
//		
//		System.out.println(threadName+")");
//		PrintOut(random);
//		for(int j=0;j<16;j++)
//		    writer.writeByte(random[j]);
//
//	    }
//	    writer.close();
//	} catch(IOException ex){
//	    ex.printStackTrace();
//	} finally {
//	    //Questo è nuovo!!!!!
//	    arc4.close();
//	    //
//	}
//    }
    
    public static void main(String[] args){

	byte Key[]={'p','i','p','p','o'};//dobbiamo farla di 128 bit e formato AES

	
	try {
	    ServerSocket serverSocket=new ServerSocket(2022);
	    Socket s=serverSocket.accept();

        // Ricezione e decifratura titolo

        DataInputStream reader=new DataInputStream(s.getInputStream());
        
        // Il primo elemento letto è la lunghezza della stringa del titolo, poi vengono letti uno ad uno i caratteri del titolo
        
        int inputLenght = reader.readInt();
        byte titleBytes[inputlenhth];

        for(i = 0; i < inputLenght; i++){
            titleBytes[i] = reader.readByte();
        }

//        decryption di titleBytes

        String title = "";
        for(i = 0; i < inputLenght; i++){
            title += String.valueOf(reader.readChar());
        }
        System.out.println(title);

//
//
//        // cifratura e invio contenuto file
//        
//        DataOutputStream writer=new DataOutputStream(s.getOutputStream());
//        
//        // close
//	    
//
//	    for(int i=0;i<30000;i++){
//		arc4.PRNG(random);
//		
//		System.out.println(threadName+")");
//		PrintOut(random);
//		for(int j=0;j<16;j++)
//		    writer.writeByte(random[j]);
//
//	    }
//	    writer.close();
	} catch(IOException ex){
	    ex.printStackTrace();
	} //finally {
//	    //Questo è nuovo!!!!!
//	    arc4.close();
//	    //
	}
}
