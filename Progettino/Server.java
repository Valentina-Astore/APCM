import java.util.Random;
import java.io.*;
import java.net.*;



public class Server {
    static int i; static int j;
    
    public static void main(String[] args){

		byte Key[]={'p','i','p','p','o'};//dobbiamo farla di 128 bit e formato AES

		AES_CFB cipher = new AES_CFB();
		
		try {
			ServerSocket serverSocket=new ServerSocket(2022);
			Socket s=serverSocket.accept();

//	        Ricezione titolo del file da inviare.

		    DataInputStream reader=new DataInputStream(s.getInputStream());
		    
//	        Il primo elemento letto è la lunghezza della stringa del titolo, poi vengono letti uno ad uno i caratteri del titolo.
		    int inputLength = reader.readInt();
		    byte[] titleBytes = new byte[inputLength];

		    for(i = 0; i < inputLength; i++){
		        titleBytes[i] = reader.readByte();
		    }

//			Decryption titolo.
			cipher.Setup("Server");
			
			String title = cipher.decrypt(titleBytes);
			System.out.println("Titolo ricevuto: "+title+"\n");
			
			cipher.close();


//			Apertura del file da inviare.
		    String testo = "";
		    try {
		        File contentFile = new File("./ServerDatabase/"+title+".txt");
		        FileInputStream contentStream = new FileInputStream(contentFile);
		        
		        char c;
		        while((c = (char) contentStream.read()) != (char)-1){
					testo +=  c;
		        }
		        
		        System.out.println("Testo da inviare:\n" + testo);
		        //System.out.println();
		        
		    } catch(Exception e) {
			    System.out.println("Error in opening the file from ServerDatabase");
			    e.printStackTrace();
		    }

//			Cifratura e invio contenuto file.

			cipher.Setup("Server");
		    
		    DataOutputStream writer = new DataOutputStream(s.getOutputStream());
		    
		    byte contentBytes[] = cipher.encrypt(testo);
		    
		    writer.writeInt(contentBytes.length);
		    for(i = 0; i < contentBytes.length; i++){
		        writer.writeByte(contentBytes[i]);
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
