import java.io.*;
import java.net.*;

public class RandomThreadClient {
    public static void PrintOut(byte[] Out){
	for(int i=0;i<Out.length;i++)
	    System.out.print(String.format("%02X",Out[i]));
	System.out.println();
    }

    public void launch(String ip){
	try {
	    // Ci connettiamo al socket del server ad indirizzo ip la cui porta aperta è 2020
	    Socket s=new Socket(ip,2022);
	    // Qui possiamo leggere il flusso di dati creato dal server ...
	    // Anche qui ho la catena di stream, ma in ingresso!
	    DataInputStream reader=new DataInputStream(s.getInputStream());
	
	    byte [] random=new byte[16];

	    for(int i=0;i<30000;i++){
		for(int j=0;j<16;j++)
		    random[j]=reader.readByte();
		System.out.print(String.format("%04d)",i));
		PrintOut(random);
	    }
	       
	    reader.close();
	} catch(IOException ex){
	    ex.printStackTrace();
	}
	
    }

    public static void main(String[] args){
	String ip;
	if(args.length>0)
	    ip=args[0];
	else /*
	       Se non mi è stato passato l'ip allora presumo che il server è la macchina locale, detta anche localhost.
	       L'indirizzo ip standard del localhost è 127.0.0.1
	     */
	    ip="127.0.0.1";
	
	RandomThreadClient client=new RandomThreadClient();
	client.launch(ip);
    }

}
