import java.io.*;
import java.net.*;
import javafx.application.Application; 
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class SimpleChatClientFX extends Application {
    // TextArea in cui vengono messi i messaggi in ingresso
    TextArea incoming;
    // TextField in cui il client inserisce il messaggio da spedire
    TextField outgoing;
    // LA connessione di rete con i flussi in lettura e scrittura
    Socket sock;
    BufferedReader reader;
    PrintWriter writer;
    //
    
    @Override
    public void start(Stage primaryStage) {
	// Setup della rete 
        setUpNetworking();
        
	// ---------Questa è la parte che ho aggiornato in JavaFX ---------------//
        primaryStage.setTitle("Simple Chat Client");
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Text scenetitle = new Text("Chat history");
        scenetitle.setFont(Font.font("Tahoma", FontWeight.NORMAL, 20));
        grid.add(scenetitle, 0, 0, 2, 1);

	// In questa area di testo vengono messi in tempo reale i messaggi che vengono dal server
	// Vedi il metodo IncomingReader
        incoming = new TextArea();
	incoming.setEditable(false);
        grid.add(incoming, 0, 1, 2,1);
	//
	
        Label msglbl = new Label("Message:");
        grid.add(msglbl, 0, 2);

	// In questa seconda area i messaggi scritti dal client
	outgoing=new TextField();
	//

	grid.add(outgoing, 1, 2);

        Button btn = new Button("Send");
        HBox hbBtn = new HBox(10);
        hbBtn.setAlignment(Pos.BOTTOM_RIGHT);
        hbBtn.getChildren().add(btn);
        grid.add(hbBtn, 1, 4);

	// Se schiaccio send, nel flusso in scrittura scrivo il testo inserito dal client nel TextField outgoing
        btn.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent e) {
		try {
		    writer.println(outgoing.getText());
		    writer.flush();
                
		}
		catch (Exception ex) {
		    ex.printStackTrace();
		}
		outgoing.setText("");
		outgoing.requestFocus();
	    }
	    });
	//

        Scene scene = new Scene(grid, 300, 275);
        primaryStage.setScene(scene);
        primaryStage.show();
	//------ Fine di JavaFX ---------------//

	// Lancio il thread che mi permette di stampare i messaggi dal server //
        Thread readerThread = new Thread(new IncomingReader());
        readerThread.start();
	//

    }

    // Apro il socket ed i flussi in lettura e scrittura
    private void setUpNetworking() {
	// L'esempio usa localhost, ma come visto nelle precedenti lezioni possiamo settare qualunque ip come server.
        try {
            sock = new Socket("127.0.0.1", 5000);
            InputStreamReader streamReader = new InputStreamReader(sock.getInputStream());
            reader = new BufferedReader(streamReader);
            writer = new PrintWriter(sock.getOutputStream());
            System.out.println("networking established");
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
    }
    //
        
    public static void main(String[] args) {
        launch(args);
    }

    // La classe che implementa runnable, dove il metodo run sta in attesa dei messaggi che provengono dal server.
    class IncomingReader implements Runnable {
        public void run() {
            String message;
            try {
                while ((message = reader.readLine()) != null) {
                    System.out.println("client read " + message);
                    incoming.appendText(message + "\n");
                }
            } catch (IOException ex)
            {
                ex.printStackTrace();
            }
        }
    }
    //
}

