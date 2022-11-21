import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class ProgramLauncher extends Application {
    
    public static void main(String[] args) {
        Application.launch(ProgramLauncher.class, args);
    }
    
    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("form.fxml"));
        
        stage.setTitle("Program Launcher");
	//        stage.setScene(new Scene(root, Settings.maxPixel, Settings.maxPixel));
	stage.setScene(new Scene(root,1024,768));
        stage.show();
	
    }
}
