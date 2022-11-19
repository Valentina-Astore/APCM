import java.io.*;
import java.net.*;

public class RandomServer {

    public void launch(){
	try {
	    // Apre la porta 2022 alle richieste esterne (di numeri casuali)
	    // Lo stesso server potrebbe aprire porte diverse per servizi diversi. Ecco perchè si usano le porte.	    
	    ServerSocket serverSocket=new ServerSocket(2022);
	    while(true){
		// Crea un socket sul quale agganciare una comunicazione.
		// Non appena il client si aggancerà, il Socket s potrà essere utilizzato come stream in Input ed Output!
		Socket s=serverSocket.accept();
		/*
		  Tramite i "data stream", in input/output, posso scrivere/leggere primitive  in Java.
		  Da poterle poi leggere/scrivere da un'altra parte (Ad esempio lato client). 
		  Qui ho un esempio di catene di flussi:
		  Il dato double viene impacchettato in un "data stream" che poi viene inviato sullo stream del socket:
		  L'oggetto writer risolve questo passaggio.
		  Avremmo potuto creare un DataOutputStream su un FileOutputStream in modo analogo!
		*/
		
		DataOutputStream writer=new DataOutputStream(s.getOutputStream());

		double random=Math.random();
		writer.writeDouble(random);
		writer.close();
		System.out.println(random);
	    }
	} catch(IOException ex){
	    ex.printStackTrace();
	}
    }

    
    public static void main(String[] args){
	RandomServer server=new RandomServer();
	server.launch();
    }
}
