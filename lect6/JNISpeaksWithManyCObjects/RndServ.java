import java.io.*;
import java.net.*;

public class RndServ {

    public void launch() {
        try {
            ServerSocket ss = new ServerSocket(2022);

            byte Key1[]={'p','i','p','p','o'};
            byte Key2[]={'p','u','p','p','o'};
            byte Key3[]={'p','a','p','p','o'};
            byte Key4[]={'p','o','p','p','o'};

            arc4JNI arc4_1 = new arc4JNI();
            arc4JNI arc4_2 = new arc4JNI();
            arc4JNI arc4_3 = new arc4JNI();
            arc4JNI arc4_4 = new arc4JNI();

            RandomThread r1 = new RandomThread(ss,Key1,arc4_1);
            RandomThread r2 = new RandomThread(ss,Key2,arc4_2);
            RandomThread r3 = new RandomThread(ss,Key3,arc4_3);
            RandomThread r4 = new RandomThread(ss,Key4,arc4_4);

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
        RndServ server = new RndServ();
        server.launch();
    }


}
