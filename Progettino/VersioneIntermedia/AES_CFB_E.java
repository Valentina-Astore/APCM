import java.io.*;

public class AES_CFB_E {

    private String FIFOIn;
    private String FIFOOut;
    FileOutputStream out;
    FileInputStream in;


    //Il metodo setup apre le pipes
    public void Setup(String id) {
	    FIFOOut = "Java2CE"+id;
	    FIFOIn  = "C2JavaE"+id;
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


    //Il metodo encrypt cifra in bytes la stringa di contenuto passata in input
    public byte[] encrypt(String plaintext){
    
        
        
//      ######    INVIO PLAINTEXT A C    ######
	    try {
	        out.write(plaintext.length());//Scrivo sulla pipe Java2CE la lunghezza del plaintext
	        for(int i = 0; i < plaintext.length(); i++) {
	            out.write((byte) plaintext.charAt(i));
	        }
	        out.write(0);//Indico al processo C che ho terminato l'invio di caratteri di plaintext
	    } catch (Exception ex){
	        System.out.println(ex);
	    }


//      ######    LETTURA CIPHERTEXT DA C    ######
        byte[] Out = new byte[plaintext.length()];
	    try {
	        for(int i = 0; i < plaintext.length(); i++){
    	        Out[i]=(byte)in.read();//Leggo dalla pipe C2JavaE il ciphertext un byte alla volta
	        }
	        
	    }catch (Exception ex){
	        System.out.println(ex);
	    }
	    
	    return Out;
    }
    

    //Il metodo close chiude le pipes
    public void close(){
	    try {
	        out.close();
	        in.close();
	    } catch (Exception ex) {
	        System.out.println(ex);
	    }
	
    }
    
}

