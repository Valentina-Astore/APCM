import java.io.StringWriter;
import java.io.PrintWriter;

import java.util.ArrayList; 
import java.util.List;
import java.util.Arrays; 
import java.util.stream.Collectors;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.text.Text;

import javafx.stage.Stage;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.StackPane;

import javafx.scene.paint.Color; 
import javafx.scene.Group; 


import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;


public class formController {
    @FXML private javafx.scene.control.Button submitButton;

    @FXML private TextField programField;
    @FXML private TextArea outputField;
    @FXML private TextArea errorField;
    
    @FXML private Text actiontarget;
    
    @FXML protected void handleSubmitButtonAction(ActionEvent event) throws Exception {

	String  progname=programField.getText();
	String prgarr[]=progname.split(" ");
	List<String> commandList=new ArrayList<String>();
		
	for(int i=0;i<prgarr.length;i++)
	    commandList.add(prgarr[i]);

	try {

	    // Crea il process builder che lancerà l'eseguibile esterno ed i suoi parametri nella lista
	    ProcessBuilder pb = new ProcessBuilder(commandList);
	    //Esegue pb. final perchè la variabile non può essere riassegnata ad un processo diverso.
	    final Process p=pb.start();


	    // Leggo l'output stdin e stderr dell'eseguibile e li metto in br e bre, rispettivamente.

	    // https://www.tutorialspoint.com/java/lang/processbuilder_command_list.htm
	    BufferedReader br=new BufferedReader(new InputStreamReader(p.getInputStream()));
	    String BufLine="";
	    String line;
            while((line=br.readLine())!=null){
		      BufLine=BufLine+line+"\n";
            }
	    // Con il seguente metto il buffer nel campo della form in JavaFX
	    outputField.setText(BufLine);
	    // Analogamente faccio per bre
	    BufferedReader bre=new BufferedReader(new InputStreamReader(p.getErrorStream()));
	    BufLine="";
	    while((line=bre.readLine())!=null){
		      BufLine=BufLine+line+"\n";
            }
	    
	    errorField.setText(BufLine);
	    //


	    
	    
	} catch (Exception ex) {
	    // Se c'è qualche errore java lo metto su errorField.
	    StringWriter sw = new StringWriter();
	    PrintWriter pw = new PrintWriter(sw);
	    ex.printStackTrace(pw);
	    sw.toString();
	    outputField.setText("");
	    errorField.setText(sw.toString());
	    //	    System.out.println(ex);
	}
	

    	//stage.close();

	
	
	
    }

}

/*
@FXML private javafx.scene.control.Button closeButton;

@FXML
private void closeButtonAction(){
    // get a handle to the stage
    Stage stage = (Stage) closeButton.getScene().getWindow();
    // do what you have to do
    stage.close();
}
*/
