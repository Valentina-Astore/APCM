
import java.io.*;

public class AES_CFB_D {
    

    private String FIFOIn;
    private String FIFOOut;
    FileOutputStream out;
    FileInputStream in;


    // Setup è il metodo che apre i due file
    public void Setup(String id) {
	    FIFOOut = "Java2CD"+id;  // creazione stringa nome del file
	    FIFOIn  = "C2JavaD"+id;

	    
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
	    
	    
	    /*AEScLaunchThread launchThread = new AEScLaunchThread(id);
	    Thread t = new Thread(launchThread);
	    t.start();
	    */


    }


    public String decrypt(byte[] ciphertext){
    
        String Out = "";
        
        
	    try {
	        // Scrivo sulla pipe Java2C la lunghezza del plaintext e poi il suo contenuto un carattere alla volta convertito in byte.
	        out.write(ciphertext.length);
	        for(int i = 0; i < ciphertext.length; i++) {
	            out.write(ciphertext[i] );
	        }
	        out.write(0);
	    } catch (Exception ex){
	        System.out.println(ex);
	    }

	    try {
	        //Che poi leggo dalla pipe C2Java
	        for(int i = 0; i < ciphertext.length; i++){
	        	char[] temp = {(char) in.read()};
    	        Out+= new String(temp) ;//forse qui aggiungere conversione intermedia in char
	        }
	        
	        
	    }catch (Exception ex){
	        System.out.println(ex);
	    }
	    
	    return Out;
    }
    

    public void close(){
	try {
	    out.close();
	    in.close();
	} catch (Exception ex) {
	    System.out.println(ex);
	}
	
	
    }
    
}

