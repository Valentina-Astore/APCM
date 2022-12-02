import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

public class TestT {
    public static void main(String[] args){
    
        
        
        try{
            ProcessBuilder p = new ProcessBuilder();

            p.command("bash", "-c","gnome-terminal -- ./AES_CFB_ED Client");

            Process process = p.start();
        }catch(IOException e){System.out.println("Error in opening ./AES_CFB_ED id");}
        
    }
}
