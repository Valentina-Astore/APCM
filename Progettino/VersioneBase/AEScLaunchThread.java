import java.io.*;
import java.net.*;

public class AEScLaunchThread implements Runnable {

    public String id;

    public AEScLaunchThread() {}

    public AEScLaunchThread ( String id ) {
        this.id = id;
    }


    public void run() {
        System.out.println("sono arrivato qui");
        try {
            
            
        ProcessBuilder p = new ProcessBuilder();

        p.command("bash", "-c", "./AES_CFB "+id+" &");

        Process process = p.start();


        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        // create a null string
        String s = null;
        // use readLine() for printing output
        while ((s = reader.readLine()) != null) {
            System.out.println(s);
        }
            
        } catch(IOException ex) {
        ex.printStackTrace();
        }

    }

}
