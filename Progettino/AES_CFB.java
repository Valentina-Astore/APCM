import java.io.*;

public class AES_CFB {
    

    private String FIFOIn;
    private String FIFOOut;
    FileOutputStream out;
    FileInputStream in;


    // Setup è il metodo che apre i due file
    public void Setup(String id) {
	    FIFOOut = "Java2C"+id;  // creazione stringa nome del file
	    FIFOIn  = "C2Java"+id;

	    
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


    }


    public byte[] encrypt(String plaintext){
    
        byte[] Out = new byte[plaintext.length()];
        
        
	    try {
	        // Scrivo sulla pipe Java2C la lunghezza del plaintext e poi il suo contenuto un carattere alla volta convertito in byte.
	        out.write(plaintext.length());
	        for(int i = 0; i < plaintext.length(); i++) {
	            out.write((byte) plaintext.charAt(i));
	        }
	        out.write(0);
	    } catch (Exception ex){
	        System.out.println(ex);
	    }

	    try {
	        //Che poi leggo dalla pipe C2Java
	        for(int i = 0; i < plaintext.length(); i++){
    	        Out[i]=(byte)in.read();
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

