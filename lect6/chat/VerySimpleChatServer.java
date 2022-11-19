import java.io.*;
import java.net.*;
import java.util.*;

//-------------Enclosing class------------------//
public class VerySimpleChatServer{
    // A differenza dei nostri random generator non vogliamo un numero fisso di client (e thread collegati).
    // Non conosciamo infatti "a priori" il numero dei client della chat.
    // In Java abbiamo le collections (e.g. TreeSet, LinkedList, ArrayList).
    // Con ArrayList posso navigare nella collezione di elementi come fosse una lista o un array.
    // E come una lista posso aggiungere nuovi elementi.
    // In questa ArrayList ho tutti gli outputstream dei singoli clienti.
    // In questo modo posso mandare a tutti i client il messaggio scritto da un singolo client.
    ArrayList clientOutputStreams;
    //
    

    // ---------Metodi della enclosing class ------//
    public static void main(String[] args) {
        new VerySimpleChatServer().go();
    }



    // Questo metodo inizializza ed aggiorna la ArrayList clientOutputStreams.
    // Ad ognuna delle nuove connessioni  associa un thread.
    // Questo è l'unico metodo lanciato direttamente dall'oggetto.
    // Vedi main()
    public void go() {
        clientOutputStreams = new ArrayList();
        try {
            ServerSocket serverSock = new ServerSocket(5000);
            while(true) {
		// Aspetto che un nuovo client si colleghi
                Socket clientSocket = serverSock.accept();

		// Appena si collega aggiungo il writer corrispondente al client,
		// che mi servirà per spedirgli i messaggi ...
		// Nota: Qui usiamo PrintWriter che "scrive" string sullo stream, un pò come printf. Da questo il nome.
		PrintWriter writer = new PrintWriter(clientSocket.getOutputStream());
		// L'ArrayList contiene oggetti del tipo "PrintWriter"
                clientOutputStreams.add(writer);
                // Infine lancio il thread legato alla classe annidate
                Thread t = new Thread(new ClientHandler(clientSocket));
                t.start();
		//
                System.out.println("got a connection");
            }
        } catch (Exception ex) { ex.printStackTrace(); }
    }

    //



//------------------Classe annidata -------------------//
    public class ClientHandler implements Runnable {
        BufferedReader reader;
        Socket sock;
        
        public ClientHandler(Socket clientSOcket) {
            try {
                sock = clientSOcket;
		// Qui InputStreamReader fa da ponte da uno stream a basso livello, l'inputStream del socket...
                InputStreamReader isReader = new InputStreamReader(sock.getInputStream())
;		// ... ad uno ad alto livello che gestisce bene le stringhe, come BufferedReader!
                reader = new BufferedReader(isReader);

            } catch (Exception ex) {
		ex.printStackTrace();
	    }
        }
        
        public void run() {
            String message;
            try {
		// Qui il thread sta in attesa che il client al quale è associato scriva qualcosa ..
                while ((message = reader.readLine()) != null) {
                    System.out.println("read " + message);
		    // ... e non appena il client scrive qualcosa ed il messaggio viene letto, esso viene rispedito a tutti! Questo metodo è della classe enclosing.
		    tellEveryone(message);
		    
                }
            } catch (Exception ex) { ex.printStackTrace(); }
        }
    }
    // -------- Fine della classe annidata -------//

    // Questo è il metodo lanciato dalla classe annidata non appena viene ricevuto un nuovo messaggio
    public void tellEveryone(String message) {
	// Per ogni elemento in clientOutputStreams ...
        Iterator it = clientOutputStreams.iterator();
        while (it.hasNext()) {
            try {
		PrintWriter writer = (PrintWriter) it.next();
		// ... mando il messaggio!
		writer.println(message);
                writer.flush();
            } catch (Exception ex) { ex.printStackTrace(); }
        }
    }
    //

}
