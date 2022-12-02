import java.io.*;
import java.net.*;




public class Client {

    static String[] usersArray = {"Paola Bruni", "Carla Gialli", "Mario Rossi", "Luigi Verdi"};
    
    static int i; static int j;


    public static void main(String[] args){

        //L'indirizzo ip del Server viene inserito da linea di comando. Il valore predefinito è la macchina locale
		String ip;
		if(args.length>0) ip=args[0];
		else ip="127.0.0.1";
		

		try {
            //Lancio dei processi ./AES_CFB_E Client e ./AES_CFB_D Client. Saranno utilizzati nella cifratura e decifratura delle comunicazioni. Per aggirare il problema che process Builder non permetta di lanciare processi in background, lanciamo i processi su due terminali accessori che verranno aperti e si chiuderanno al termine del processo		
		    ProcessBuilder pE = new ProcessBuilder();
            pE.command("bash", "-c","gnome-terminal -- ./AES_CFB_E Client");
            Process processE = pE.start();

            ProcessBuilder pD = new ProcessBuilder();
            pD.command("bash", "-c","gnome-terminal -- ./AES_CFB_D Client");
            Process processD = pD.start();
            
            
            //Apertura e setup dei due processi di cifratura/decifratura. Ci assicuriamo con try-catch che vengano sicuramente entrambi chiusi 
		    AES_CFB_E cipherE = new AES_CFB_E();
		    AES_CFB_D cipherD = new AES_CFB_D();
            cipherE.Setup("Client");
            cipherD.Setup("Client");


            //Creazione del canale di comunicazione con il Server
            Socket s=new Socket(ip,2022);        
	        DataOutputStream writer=new DataOutputStream(s.getOutputStream());
		    DataInputStream reader=new DataInputStream(s.getInputStream());
		    
		    	        
            try{
//              #########   INVIO RICHIESTA   #########
            
            
                //Inserimento del nome dell'utente da console
		        Console console = System.console();
		        if (console == null) {
		            System.out.println("Couldn't get Console instance");
		            System.exit(0);
		        }
			    String user;
			    boolean flag = true;//flag == true --> il nome utente inserito non è nel database 
			    boolean firstTime = true; // firstTime == true --> è il primo tentativo di inserimento del nome utente
			    do{
			        //Stampa a video la query
			        if(firstTime){System.out.println("Inserire [Nome] [Cognome]."); firstTime = false;}
			        else{System.out.println("Il nominativo non compare nel database. Inserire nuovamente [Nome] [Cognome].");}
			        
			        //Acquisizione nome
			        user = new String(console.readPassword(">"));
			        
			        //Verifica che il nome inserito sia presente nella lista di controllo
			        for (i = 0; i < usersArray.length; i++ ) {flag = flag && !(usersArray[i].equals(user));}			 
		        } while(flag);//Continua a richiedere il nome utente fino a che il nome utente non è nella lista di controllo usersArray
		        
		        	
		        //Cifratura del nome utente		        
		        byte userBytes[] = cipherE.encrypt(user);
		        		        
		    
		        //Invio titolo tramite il Socket
		        //Inviamo la lunghezza del nome utente da mandare
		        writer.writeInt(userBytes.length);
		        
		        //Inviamo il cifrato del nome utente
		        for(i = 0; i < userBytes.length; i++){
		            writer.writeByte(userBytes[i]);
		        }
		        

//              #########   RISPOSTA DEL SERVER   #########
			    
	    
	            //Acquisizione cifrato del contenuto
		        int inputLength = reader.readInt(); //Acquisizione lunghezza del contenuto
		        byte[] contentBytes = new byte[inputLength];
		        for(i = 0; i < inputLength; i++){
		            contentBytes[i] = reader.readByte();//Acquisizione cifrato del contenuto
		        }
		        
		        
		        //Decifratura contenuto
		        String content = cipherD.decrypt(contentBytes);
		        
		        //Stampa a video del contenuto
			    System.out.println("\nTesto ricevuto: \n" + content);

            
            }catch(IOException e){throw e;} finally {
                cipherD.close();
                cipherE.close();
                reader.close();
	        	writer.close(); 
            }

	
		} catch(IOException ex){
		    ex.printStackTrace();
		}

    }
}
