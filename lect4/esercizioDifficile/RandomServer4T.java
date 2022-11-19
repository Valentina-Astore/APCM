import java.io.*;
import java.net.*;

public class RandomServer4T {

    public void launch() {
        try {
            ServerSocket ss = new ServerSocket(2022);

            RandomThread r1 = new RandomThread(ss);
            RandomThread r2 = new RandomThread(ss);
            RandomThread r3 = new RandomThread(ss);
            RandomThread r4 = new RandomThread(ss);

            Thread t1 = new Thread(r1);
            Thread t2 = new Thread(r2);
            Thread t3 = new Thread(r3);
            Thread t4 = new Thread(r4);

            t1.setName("t1");
            t2.setName("t2");
            t3.setName("t3");
            t4.setName("t4");

            t1.start();
            t2.start();
            t3.start();
            t4.start();

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args){
        RandomServer4T server = new RandomServer4T();
        server.launch();
    }


}
