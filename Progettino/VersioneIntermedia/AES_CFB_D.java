import java.io.*;

public class AES_CFB_D {

    private String FIFOIn;
    private String FIFOOut;
    FileOutputStream out;
    FileInputStream in;


    //Il metodo setup apre le pipes
    public void Setup(String id) {
	    FIFOOut = "Java2CD"+id;
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
	    
    }


    //Il metodo decrypt decifra i bytes passati in input restituendo una stringa
    public String decrypt(byte[] ciphertext){
        
//      ######    INVIO CIPHERTEXT A C    ######
	    try {
	        out.write(ciphertext.length);//Scrivo sulla pipe Java2CD la lunghezza del ciphertext
	        for(int i = 0; i < ciphertext.length; i++) {
	            out.write(ciphertext[i] );//Scrivo sulla pipe Java2CD il ciphertext un carattere alla volta
	        }
	        out.write(0);//Indico al processo C che ho terminato l'invio di bytes di ciphertext
	    } catch (Exception e){
	        System.out.println(e);
	    }


//      ######    LETTURA PLAINTEXT DA C    ######
        String Out = "";
	    try {
	        for(int i = 0; i < ciphertext.length; i++){
	        	char[] temp = {(char) in.read()};//Leggo dalla pipe C2JavaD il plaintext un carattere alla volta
    	        Out+= new String(temp);//Aggiungo il nuovo carattere acquisito alla stringa Out
	        }
	        
	    }catch (Exception e){
	        System.out.println(e);
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

