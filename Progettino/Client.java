import java.io.*;
import java.net.*;




public class Client {

    static String[] titlesArray = {"ricetta torta alle mele", "testo La Guerra Di Piero"};
    
    static int i; static int j;


    public static void main(String[] args){
		String ip;
		if(args.length>0) ip=args[0];
		else ip="127.0.0.1";
		
		AES_CFB cipher = new AES_CFB();

		try {
			 Socket s=new Socket(ip,2022);
		    
		    // stampa dei titoli disponibili
		    for (i=0; i<Client.titlesArray.length; i++){System.out.println("file "+ i + ":  " + Client.titlesArray[i]);}

		    // scelta del titolo da console
		    Console console = System.console();
		    if (console == null) {
		        System.out.println("Couldn't get Console instance");
		        System.exit(0);
		    }
			String title = new String(console.readPassword(">"));
		    
		    // invio titolo
		    DataOutputStream writer=new DataOutputStream(s.getOutputStream());
	//        writer.writeInt(title.length());
		    
		    cipher.Setup("Client");
		    
		    byte titleBytes[] = cipher.encrypt(title);
		    
		    writer.writeInt(titleBytes.length);
		    for(i = 0; i < titleBytes.length; i++){
		        writer.writeByte(titleBytes[i]);
	//            System.out.println(titleBytes[i]);
		    }
		    
		    cipher.close();
	  

	//		ricezione testo e decifratura
			cipher.Setup("Client");
	
			DataInputStream reader=new DataInputStream(s.getInputStream());
		
			int inputLength = reader.readInt();
		    byte[] contentBytes = new byte[inputLength];

		    for(i = 0; i < inputLength; i++){
		        contentBytes[i] = reader.readByte();
		    }
		    
		    String content = cipher.decrypt(contentBytes);
			System.out.println("Testo ricevuto: " + content);
			
			reader.close();
	    	writer.close();
		     
			
		} catch(IOException ex){
		    ex.printStackTrace();
		} finally {
		    cipher.close();
		}

    }
}
