
public class RandomClient4Trun {

    public void launch(String ip) {

        ClientThread c1 = new ClientThread(ip);
        ClientThread c2 = new ClientThread(ip);
        ClientThread c3 = new ClientThread(ip);
        ClientThread c4 = new ClientThread(ip);

        Thread t1 = new Thread(c1);
        Thread t2 = new Thread(c2);
        Thread t3 = new Thread(c3);
        Thread t4 = new Thread(c4);

        t1.setName("1");
        t2.setName("2");
        t3.setName("3");
        t4.setName("4");

        t1.start();
        t2.start();
        t3.start();
        t4.start();

    }

    public static void main(String[] args){

        String ip;
        if(args.length>0) ip=args[0];
        else ip="127.0.0.1";

        RandomClient4Trun client = new RandomClient4Trun();
        client.launch(ip);
    }
}
