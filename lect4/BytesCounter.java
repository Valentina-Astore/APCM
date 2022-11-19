import java.io.*;

public class BytesCounter {
    public static void main(String args[]) throws IOException {  
	FileInputStream in = null;
	char ct;
	int ncol;
	if(args.length != 2) {
	    System.out.println("java BytesCounter filein ncol");
	    System.exit(0);
	} try {
	    in = new FileInputStream(args[0]);
	    ncol= Integer.parseInt(args[1]);
	    int []  counter=new int[256]; 
   	    int c;
	    while ((c = in.read()) != -1) {
		counter[c]++;
	    }
	    for(c=0;c<256;c++) {
		if(c>=32 && c<=126) ct=(char)c;
		else ct=' ';
		System.out.format("%02X:%03d:%c ",c,counter[c],ct);
		if((c+1)%ncol==0) System.out.println();
	    }
	    
	    System.out.println();
	}finally {
	    if (in != null) {
		in.close();
	    }
	}
    }
}
