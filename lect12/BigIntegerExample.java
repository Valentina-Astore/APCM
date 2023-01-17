// Ecco la classe dei BigInteger
import java.math.BigInteger;
/**
 *
 * @author gianchi
 */
public class BigIntegerExample {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // La probailita' che il metodo dia un numero primo e' p=1 - 1/2^c=(2^c-1)/2^c.
	// Quindi c=1 => p=1/2
	//        c=2 => p=3/4
	//        c=3 => p=7/8
        int c=1;
        int d=2;
	int e=3;
	//Defininisco un BigInteger con valore iniziale 2
        BigInteger v = BigInteger.valueOf(2);
     
        for(int i = 2; i < 100000; i++) {          
	    // e controllo se è primo con probablità crecenti:c,d,e.
	    if (v.isProbablePrime(c)) {
                System.out.print(v+" ");
                if (v.isProbablePrime(d)) {
                    System.out.print(v+" ");
		    if (v.isProbablePrime(e)) {
			System.out.print(v+" ");
		    }
		}
                System.out.println();
            }
	    //Incremento il valore di v
	    v = v.add(BigInteger.valueOf(1));
        }
        
    }
    
}
