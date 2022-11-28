import java.io.*;
import java.net.*;




public class Client {
    
    static int i; static int j;


    public static void main(String[] args){
	String ip;
	if(args.length>0) ip=args[0];
	else ip="127.0.0.1";

    String[] titles = {"brontolo", "mammolo", "pisolo", "cucciolo", "dotto", "gongolo", "eolo"};
    

    try {
	     Socket s=new Socket(ip,2022);
        
        // stampa dei titoli disponibili
        for (i=0; i<titles.length; i++){System.out.println("file "+ i + ":  " + titles[i]);}

        // scelta del titolo da console
        Console console = System.console();
        if (console == null) {
            System.out.println("Couldn't get Console instance");
            System.exit(0);
        }
	    String title = new String(console.readPassword(">"));

        // invio titolo
        DataOutputStream writer=new DataOutputStream(s.getOutputStream());
        writer.writeInt(title.length());
        byte titleBytes[] = encrypt(title);
        for(i = 0; i < title.length(); i++){writer.writeByte(titleBytes[i]);}

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
