import java.io.*;
import java.util.Arrays;
public class HexViz {
    public static void main(String args[]) throws IOException {  
	String digits = "0123456789abcdef";

	FileInputStream in = null;
	if(args.length != 1) {
		System.out.println("java HexViz filein");
		System.exit(0);
	} try {
	    in = new FileInputStream(args[0]);
	    int c;
	    short col=0;
	    byte[] buf = new byte[15];

	    while ((c = in.read()) != -1) {
		System.out.format("%02X ", c);
		if(c>=32 && c<127)
		    buf[col]=(byte)c;
		else
		    buf[col]='.';

		col++;
		if(col==15) {
		    col=0;
		    System.out.println(new String(buf));
		}
	    }
	    if(col<15) for(c=0;c<col;c++) System.out.format("%c",(char)buf[c]);
	    System.out.println();
	}finally {
	    if (in != null) {
		in.close();
	    }
	}
    }
}
