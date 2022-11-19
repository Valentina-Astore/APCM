import java.io.*;
import java.net.*;

public class RandomThread implements Runnable {

    public ServerSocket ServerSocketDelThread;
    public byte Key[];
    public arc4JNI arc4;

    public RandomThread() {
    }

    public RandomThread (ServerSocket ss, byte[] key, arc4JNI arc4) {
        this.ServerSocketDelThread = ss;
        this.Key = key;
        this.arc4 = arc4;    
    }

    public static void PrintOut16(byte[] Out, int ii){
        
        String threadName = Thread.currentThread().getName();
        String toPrint = "thread "+threadName + ", serie "+Integer.toString(ii)+"   ";

	    for(int i=0;i<Out.length;i++)
	        toPrint += String.format("%02X. ",Out[i]);

        System.out.println(toPrint);
    }


    public void run() {

        try {
            Socket s = ServerSocketDelThread.accept();
            DataOutputStream writer = new DataOutputStream(s.getOutputStream());

            String threadName = Thread.currentThread().getName();
            
	        byte Out[];
	        Out=new byte [16];

            arc4.Setup(Key);

            for (int i = 0; i < 10; i++) {
                arc4.PRNG(Out);
                for (int j = 0; j < 16; j++){
                    writer.writeByte(Out[j]);
                }
                
                PrintOut16(Out,i);
            }
	        
            writer.close();

        } catch(IOException ex) {
        ex.printStackTrace();
        }

    }

}
