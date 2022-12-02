import java.util.Random;
import java.io.*;
import java.net.*;



public class Server {
    static int i; static int j;

    
    public static void main(String[] args){

		byte Key[]={'p','i','p','p','o'};//dobbiamo farla di 128 bit e formato AES

		AES_CFB_E cipherE = new AES_CFB_E();
		AES_CFB_D cipherD = new AES_CFB_D();
		
		try {
			ServerSocket serverSocket=new ServerSocket(2022);
			Socket s=serverSocket.accept();

// 		       Ricezione titolo

		    DataInputStream reader=new DataInputStream(s.getInputStream());
		    
//	        Il primo elemento letto è la lunghezza della stringa del titolo, poi vengono letti uno ad uno i caratteri del titolo
		    
		    int inputLength = reader.readInt();
		    byte[] titleBytes = new byte[inputLength];

		    for(i = 0; i < inputLength; i++){
		        titleBytes[i] = reader.readByte();
		    }

//	        decryption titolo
			cipherD.Setup("Server");
			
			String title = cipherD.decrypt(titleBytes);
			System.out.println("Titolo ricevuto: "+title);

			cipherD.close();

//		  	Apertura del file da inviare
		    String testo = "";
		    try {
		        File contentFile = new File("./ServerDatabase/"+title+".txt");
		        FileInputStream contentStream = new FileInputStream(contentFile);
		        
		        char c;
		        while((c = (char) contentStream.read()) != (char)-1){
					testo +=  c;
		        }
		        
		    } catch(Exception e) {
			    System.out.println("Error in opening the file from ServerDatabase.");
		    }

//			cifratura e invio contenuto file


			cipherE.Setup("Server");
		    
		    DataOutputStream writer = new DataOutputStream(s.getOutputStream());
		    
		    byte contentBytes[] = cipherE.encrypt(testo);
		    
		    
		    writer.writeInt(contentBytes.length);
		    for(i = 0; i < contentBytes.length; i++){
		        writer.writeByte(contentBytes[i]);
		    }

			reader.close();
			writer.close();

		} catch(IOException ex){
			ex.printStackTrace();
		} finally {
			cipherE.close();
		}
	
	}
}
