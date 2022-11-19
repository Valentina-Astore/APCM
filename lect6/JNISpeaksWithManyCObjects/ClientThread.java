import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientThread implements Runnable {

    public String Clientip;

    public ClientThread(String ip) {
        this.Clientip = ip;
    }

    public static void PrintOut16(byte[] Out, int ii){
        
        String threadName = Thread.currentThread().getName();
        String toPrint = "client "+threadName + ", serie "+Integer.toString(ii)+"   ";

	    for(int i=0;i<Out.length;i++)
	        toPrint += String.format("%02X. ",Out[i]);

        System.out.println(toPrint);
    }

    public void run(){
        try {
            Socket s = new Socket(Clientip,2022);

            DataInputStream reader = new DataInputStream(s.getInputStream());

            byte Out[];
	        Out=new byte [16];
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 16; j++){
                    Out[j] = reader.readByte();
                }
            
                PrintOut16(Out,i);
            
            }
            reader.close();

        } catch(IOException ex) {
            ex.printStackTrace();
        }

    }


}
