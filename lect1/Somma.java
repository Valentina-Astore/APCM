import java.io.*;

public class Somma {
    public static void main(String args[]) throws IOException {  
	int narg=args.length;
	int i,somma=0;
	for(i=0;i<narg;i++) {
	    somma+= Integer.parseInt(args[i]);
	}
	System.out.format("Somma=%d\n",somma);
    }
}
