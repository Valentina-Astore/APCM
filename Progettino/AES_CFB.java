


//      TUTTO DA CAMBIARE

// fare un metodo encrypt che prende in input una striga e la converte in bytes carattere per carattere.


import java.io.*;

public class arc4 {
    
    // Counter che mi dice il numero di sessioni finora lanciate. Ovviamente è static!
    // Ma nell'attuale implementazione non è usato
    static int counter=0;
    // "id" mi identifica l'oggetto: quindi è una variabile di istanza.
    private int id;

    //    private String FIFO = "Java2C000";
    private String FIFOIn;
    private String FIFOOut;
    FileOutputStream out;
    FileInputStream in;

    
    public int id(){return id;}


    // Setup è il metodo che apre i due file
    public void Setup(byte[] Key, int idv) {
	id=idv;  // è il nome del thread
	FIFOOut = "Java2C"+String.format("%03d",id);  // creazione stringa nome del file
	FIFOIn  = "C2Java"+String.format("%03d",id);
	System.out.println(FIFOOut);

	
	try {
	    out = new FileOutputStream(FIFOOut);
	} catch (Exception ex){
	    System.out.println(ex);
	}
	
 	try {
	    in = new FileInputStream(FIFOIn);
	} catch (Exception ex){
	    System.out.println(ex);
	}	    


	// Purtroppo non sono riuscito (e navigando in internet penso sia un limite del ProcessBuilder) a lanciare l'eseguibile in background
	// tramite ProcessBuilder di Java. Quindi dobbiamo lanciare gli eseguibili esternamente. Poco male, ovviamente.
	/*	
	try {
	    ProcessBuilder pb = new ProcessBuilder("nohup", "./PRNG", String.format("%d",id), "pippo");
	    System.out.println(String.format("%d",id));
	    // ProcessBuilder pb = new ProcessBuilder("./PRNG", String.format("%d",id), "pippo");
	     final Process p=pb.start();
	 } catch (Exception ex) {
	      System.out.println(ex);
	 }
	*/
    }

    public void PRNG(byte[] Out){

	

	try {
	    // Sto chiedendo 16 byte random alla volta, scrivendo sulla pipe Java2C
	    out.write(new byte[]{16});
	} catch (Exception ex){
	    System.out.println(ex);
	}

	try {
	    //Che poi leggo dalla pipe C2Java
	    for(int i=0;i<16;i++) Out[i]=(byte)in.read();
	}catch (Exception ex){
	    System.out.println(ex);
	}
	
    }

    //Aggiungo il metodo close per chiudere le due pipe
    //Solo se i processi produttore e consumatore chiudono i file il sistema di comunicazione viene correttamente completato.
    public void close(){
	try {
	    out.close();
	    in.close();
	} catch (Exception ex) {
	    System.out.println(ex);
	}
	
	
    }
    //
    
}

