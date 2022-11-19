import java.io.*;
import java.net.*;

public class RandomThread implements Runnable {
    public ServerSocket ServerSocketDelThread;

    public RandomThread() {
    }

    public RandomThread (ServerSocket ss) {
        this.ServerSocketDelThread = ss;
    }


    public void run() {

        try {
            Socket s = ServerSocketDelThread.accept();
            DataOutputStream writer = new DataOutputStream(s.getOutputStream());

            String threadName = Thread.currentThread().getName();

            double random;
            for (int i = 0; i < 10; i++) {
                random = Math.random();
                writer.writeDouble(random);
                System.out.println(threadName + " " + random);
            }
            writer.close();
        } catch(IOException ex) {
        ex.printStackTrace();
        }

    }

}
