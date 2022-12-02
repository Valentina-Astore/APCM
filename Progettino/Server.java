import java.util.Random;
import java.io.*;
import java.net.*;



public class Server {
    static int i; static int j;

    
    public static void main(String[] args){
    
    
        try{
            //Lancio dei processi ./AES_CFB_E Server e ./AES_CFB_D Server. Saranno utilizzati nella cifratura e decifratura delle comunicazioni. Per aggirare il problema che process Builder non permetta di lanciare processi in background, lanciamo i processi su due terminali accessori che verranno aperti e si chiuderanno al termine del processo	
            ProcessBuilder pD = new ProcessBuilder();
            pD.command("bash", "-c","gnome-terminal -- ./AES_CFB_D Server");
            Process processD = pD.start();
    
            ProcessBuilder pE = new ProcessBuilder();
            pE.command("bash", "-c","gnome-terminal -- ./AES_CFB_E Server");
            Process processE = pE.start();
            
            
            //Apertura e setup dei due processi di cifratura/decifratura. Ci assicuriamo con try-catch che vengano sicuramente entrambi chiusi             
            AES_CFB_E cipherE = new AES_CFB_E();
		    AES_CFB_D cipherD = new AES_CFB_D();
		    cipherD.Setup("Server");
		    cipherE.Setup("Server");	
		    
		    	    
	        //Creazione del canale di comunicazione con il Client. 
	        ServerSocket serverSocket=new ServerSocket(2022);
		    Socket s=serverSocket.accept();
		    DataInputStream reader=new DataInputStream(s.getInputStream());
		    DataOutputStream writer = new DataOutputStream(s.getOutputStream());
		    
		    
		    try {
//              #########   QUERY DEL CLIENT   #########
		        int inputLength = reader.readInt();//Acquisiamola lunghezza del nome utente richiesto
		        
		        //Acquisiamo il cifrato del nome utente
		        byte[] userBytes = new byte[inputLength];
		        for(i = 0; i < inputLength; i++){
		            userBytes[i] = reader.readByte();
		        }

			    
			    //Decifriamo il nome utente
			    String user = cipherD.decrypt(userBytes);
			    
			    //Stampa a video del nome utente
			    System.out.println("Nome utente ricevuto: "+user);
			    

                //Apertura del file da inviare
		        String content = "";
		        File contentFile = new File("./ServerDatabase/"+user+".txt");
	            FileInputStream contentStream = new FileInputStream(contentFile);
		        try {
		            char c;
		            while((c = (char) contentStream.read()) != (char)-1){
					    content +=  c;
		            }
		        } catch(IOException e) {
		            throw new IOException("Error in opening the file from ServerDatabase.");
		        } finally {contentStream.close();}
		        
		        
		        //Stampa a video del contenuto da inviare
		        System.out.println("\nContenuto da inviare:\n"+content);
		        
		        
		        //Cifratura del contenuto
		        byte contentBytes[] = cipherE.encrypt(content);
		        
		        
		        //Invio del cifrato del contenuto
		        writer.writeInt(contentBytes.length);
		        for(i = 0; i < contentBytes.length; i++){
		            writer.writeByte(contentBytes[i]);
		        }


		    } catch(IOException ex){
			    ex.printStackTrace();
		    } finally {
			    cipherE.close();
			    cipherD.close();
			    reader.close();
			    writer.close();
		    }
		    
        }catch(IOException ex){
		    ex.printStackTrace();
	    }
    
	
	}
}
