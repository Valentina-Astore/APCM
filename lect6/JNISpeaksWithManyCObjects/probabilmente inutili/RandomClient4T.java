import java.io.*;
import java.net.*;

public class RandomClient4T {

    public void launch(String ip){
        try {
            Socket s = new Socket(ip,2022);

            DataInputStream reader = new DataInputStream(s.getInputStream());

            double random;
            //for (int i = 0; i < 500; i++) {
            while (reader.available() > 0) {
                random = reader.readDouble();
                System.out.println(random);
            }
            reader.close();

        } catch(IOException ex) {
            ex.printStackTrace();
        }

    }

    public static void main(String[] args){

        String ip;
        if(args.length>0) ip=args[0];
        else ip="127.0.0.1";

        RandomClient4T client = new RandomClient4T();

        client.launch(ip);
    }
}
