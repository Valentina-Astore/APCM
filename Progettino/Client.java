import java.io.*;
import java.net.*;




public class Client {

    static String[] titlesArray = {"ricetta torta alle mele", "testo La Guerra Di Piero"};
    
    static int i; static int j;


    public static void main(String[] args){
	String ip;
	if(args.length>0) ip=args[0];
	else ip="127.0.0.1";
    

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
        
        AES_CFB cipher = new AES_CFB();
        cipher.Setup("Client");
        System.out.println("dopo setup");
        
        byte titleBytes[] = cipher.encrypt(title);
        
        writer.writeInt(titleBytes.length);
        for(i = 0; i < titleBytes.length; i++){
            writer.writeByte(titleBytes[i]);
//            System.out.println(titleBytes[i]);
        }
        
//        for(i = 0; i < title.length(); i++){writer.writeChar(title.charAt(i));}   //versione di prova in cui viene inviato il testo in chiaro

//        
//        
//
//
//
//
//
//	    DataInputStream reader=new DataInputStream(s.getInputStream());
//	    
//	    double random=reader.readDouble();
//		  
//	    System.out.println(random);
//	    reader.close();
	    
	    } catch(IOException ex){
	        ex.printStackTrace();
	    }

    }
}
