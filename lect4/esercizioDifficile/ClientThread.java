import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientThread implements Runnable {

    public String Clientip;

    public ClientThread(String ip) {
        this.Clientip = ip;
    }

    public void run(){
        try {
            Socket s = new Socket(Clientip,2022);

            DataInputStream reader = new DataInputStream(s.getInputStream());

            String threadName = Thread.currentThread().getName();

            double random;
            for (int i = 0; i < 10; i++) {
                //while (reader.available() > 0) {
                random = reader.readDouble();
                System.out.println("client " + threadName+" --> "+random);
            }
            reader.close();

        } catch(IOException ex) {
            ex.printStackTrace();
        }

    }


}
