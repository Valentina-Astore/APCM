import java.io.*;
import java.net.*;

public class RandomThread implements Runnable {

    public ServerSocket ServerSocketDelThread;

    public byte Key[];

    public RandomThread() {
    }

    public RandomThread (ServerSocket ss, byte[] key) {
        this.ServerSocketDelThread = ss;
        this.Key = key;
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

            if(Thread.currentThread().getName() == "t1") {

                Socket s1 = ServerSocketDelThread.accept();
                DataOutputStream writer1 = new DataOutputStream(s1.getOutputStream());
                byte Out1[] =new byte [16];

                arc4JNI arc4_t1 = new arc4JNI();
                arc4_t1.Setup(Key);

                for (int i = 0; i < 10; i++) {
                    arc4_t1.PRNG(Out1);
                    System.out.println("\n\n"+"t1: "+arc4_t1.id()+"  i = "+i);
                    for (int j = 0; j < 16; j++){
                        writer1.writeByte(Out1[j]);
                    }
                    
                    PrintOut16(Out1,i);
                }writer1.close();

            } else if (Thread.currentThread().getName() == "t2") {

                Socket s2 = ServerSocketDelThread.accept();
                DataOutputStream writer2 = new DataOutputStream(s2.getOutputStream());
                byte Out2[] =new byte [16];

                arc4JNI arc4_t2 = new arc4JNI();
                arc4_t2.Setup(Key);


                for (int i = 0; i < 10; i++) {
                    arc4_t2.PRNG(Out2);
                    System.out.println("\n\n"+"t2: "+arc4_t2.id()+"  i = "+i);
                    for (int j = 0; j < 16; j++){
                        writer2.writeByte(Out2[j]);
                    }
                    
                    PrintOut16(Out2,i);
                }writer2.close();

            } else if (Thread.currentThread().getName() == "t3") {

                Socket s3 = ServerSocketDelThread.accept();
                DataOutputStream writer3 = new DataOutputStream(s3.getOutputStream());
                byte Out3[] =new byte [16];

                arc4JNI arc4_t3 = new arc4JNI();
                arc4_t3.Setup(Key);

                for (int i = 0; i < 10; i++) {
                    arc4_t3.PRNG(Out3);
                    System.out.println("\n\n"+"t3: " +arc4_t3.id()+"  i = "+i);
                    for (int j = 0; j < 16; j++){
                        writer3.writeByte(Out3[j]);
                    }
                    
                    PrintOut16(Out3,i);
                }writer3.close();

            } else if (Thread.currentThread().getName() == "t4"){

                Socket s4 = ServerSocketDelThread.accept();
                DataOutputStream writer4 = new DataOutputStream(s4.getOutputStream());
                byte Out4[] =new byte [16];

                arc4JNI arc4_t4 = new arc4JNI();
                arc4_t4.Setup(Key);

                for (int i = 0; i < 10; i++) {
                    System.out.println("\n\n"+"t4: "+arc4_t4.id()+"  i = "+i);
                    arc4_t4.PRNG(Out4);
                    for (int j = 0; j < 16; j++){
                        writer4.writeByte(Out4[j]);
                    }
                    
                    PrintOut16(Out4,i);
                }writer4.close();
            }
            else System.out.print(Thread.currentThread().getName());
	        
            

        } catch(IOException ex) {
        ex.printStackTrace();
        }

    }

}
