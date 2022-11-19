import java.io.*;
public class HexVizBlock {
  public static void main(String args[]) throws IOException {  
    byte maxbuf=16;
    byte nread,i;
    byte[] bufin = new byte[maxbuf];

    FileInputStream in = null; // Ogni variabile reference può essere inizializzata alla costante null
    if(args.length != 1) {
      System.out.println("java HexViz filein");
      System.exit(0);
    } try {
      in = new FileInputStream(args[0]); //Apro lo stream
      do{
        nread =(byte) in.read(bufin);
        //si comporta essenzialmente come fread.
        //Ma posso anche leggere un byte alla volta con
        // c=in.read();

        for(i=0;i<nread;i++)
          System.out.format("%02X ",bufin[i]); //Tramite format posso simulare il "printf"
        if(nread<maxbuf)
          for(int j=i;j<maxbuf;j++) System.out.print("   ");

        for(i=0;i<nread;i++)
          if(bufin[i]>=32 && bufin[i]<=126)
            System.out.format("%c",(char)bufin[i]); // Nota: Per C char/int sono uguali. In Java dobbiamo fare un cast!
          else
            System.out.print(".");

        System.out.println();

      } while (nread==maxbuf);
    } finally { // Qualunque cosa accada se il file è aperto chiudilo!
      if (in != null) {
        in.close();
      }
    }
  }
}
