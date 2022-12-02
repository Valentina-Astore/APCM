import java.io.*;
import java.net.*;




public class Client {

    static String[] titlesArray = {"Carla Gialli", "Mario Rossi", "Luigi Verdi"};
    
    static int i; static int j;


    public static void main(String[] args){
		String ip;
		if(args.length>0) ip=args[0];
		else ip="127.0.0.1";
		
		AES_CFB_E cipherE = new AES_CFB_E();
		AES_CFB_D cipherD = new AES_CFB_D();

		try {
			 Socket s=new Socket(ip,2022);
		    
		    // stampa dei titoli disponibili
		    for (i=0; i<Client.titlesArray.length; i++){System.out.println("studente "+ (i+1)+ ":  " + Client.titlesArray[i]);}
		    System.out.println();

		    // scelta del titolo da console
		    Console console = System.console();
		    if (console == null) {
		        System.out.println("Couldn't get Console instance");
		        System.exit(0);
		    }
		    
			String title;
			boolean flag = true; //flag == true --> il titolo inserito non è nel database 
			do{
			    System.out.println("Inserire lo studente desiderato.");
			    title = new String(console.readPassword(">"));
			    for (i = 0; i < titlesArray.length; i++ ) {flag = flag && !(titlesArray[i].equals(title));}
		    }while(flag);
		    
		    
		    // invio titolo
		    DataOutputStream writer=new DataOutputStream(s.getOutputStream());
	//        writer.writeInt(title.length());
		    
		    cipherE.Setup("Client");
		    
		    byte titleBytes[] = cipherE.encrypt(title);
		    
		    writer.writeInt(titleBytes.length);
		    for(i = 0; i < titleBytes.length; i++){
		        writer.writeByte(titleBytes[i]);
	//            System.out.println(titleBytes[i]);
		    }
		    cipherE.close();
	  

	//		ricezione testo e decifratura
			cipherD.Setup("Client");
	
			DataInputStream reader=new DataInputStream(s.getInputStream());
		
			int inputLength = reader.readInt();
		    byte[] contentBytes = new byte[inputLength];

		    for(i = 0; i < inputLength; i++){
		        contentBytes[i] = reader.readByte();
		    }
		    
		    String content = cipherD.decrypt(contentBytes);
			System.out.println("Testo ricevuto: \n" + content);
			
			reader.close();
	    	writer.close();
		     
			
		} catch(IOException ex){
		    ex.printStackTrace();
		} finally {
		    cipherD.close();
		}

    }
}
