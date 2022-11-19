import java.math.BigInteger;
import java.util.Random;
import java.io.*;
import java.net.*;

public class RandomThreadServer implements Runnable {

    public void launch(){
	try {

	    ServerSocket serverSocket=new ServerSocket(2020);
	    while(true){

		Socket s=serverSocket.accept();
		DataOutputStream writer=new DataOutputStream(s.getOutputStream());

		double random=getRandom();
		writer.writeDouble(random);
		writer.close();
		System.out.println(random);
	    }
	} catch(IOException ex){
	    ex.printStackTrace();
	}
    }
    
    public static void main(String[] args){
	RandomServer server=new RandomServer();
	server.launch();
    }
}
