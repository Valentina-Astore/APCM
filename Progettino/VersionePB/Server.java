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

		AES_CFB cipher = new AES_CFB();
		
		try {
			ServerSocket serverSocket=new ServerSocket(2022);
			Socket s=serverSocket.accept();

	//        Ricezione titolo

		    DataInputStream reader=new DataInputStream(s.getInputStream());
		    
	//        Il primo elemento letto è la lunghezza della stringa del titolo, poi vengono letti uno ad uno i caratteri del titolo
		    
		    int inputLength = reader.readInt();
		    byte[] titleBytes = new byte[inputLength];

		    for(i = 0; i < inputLength; i++){
		        titleBytes[i] = reader.readByte();
		    }

	//        decryption titolo
			cipher.Setup("Server");
			
			String title = cipher.decrypt(titleBytes);
			System.out.println("Titolo ricevuto: "+title);
			
			cipher.close();


	//		  Apertura del file da inviare
		    try {
		        File contentFile = new File("./ServerDatabase/"+title+".txt");
		        FileInputStream contentStream = new FileInputStream(contentFile);
		        
		        String testo = "";
		        char c;
		        while((c = (char) contentStream.read()) != (char)-1){
					testo +=  c;
		        }
		        
		        System.out.println(testo);
		        
		    } catch(Exception e) {
			    System.out.println("Error in opening the file from ServerDatabase");
			    e.printStackTrace();
		    }

	//		      cifratura e invio contenuto file

			cipher.Setup("Server");
		    
		    DataOutputStream writer = new DataOutputStream(s.getOutputStream());
		    
		    byte contentBytes[] = cipher.encrypt(title);
		    
		    writer.writeInt(contentBytes.length);
		    for(i = 0; i < contentBytes.length; i++){
		        writer.writeByte(contentBytes[i]);
		        System.out.println(contentBytes[i]);
		    }

			reader.close();
			writer.close();

		} catch(IOException ex){
			ex.printStackTrace();
		} finally {
			cipher.close();
		}
	
	}
}
