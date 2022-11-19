public class arc4JNI {
    // Counter che mi dice il numero di sessioni finora lanciate. Ovviamente è static!
    static int counter=0;
    // "id" mi identifica l'oggetto: quindi è una variabile di istanza.
    private int id;
    // Il costruttore appena creato un nuovo oggetto gli dà un suo id.
    public arc4JNI(){
	id=counter;
	counter++;
    }
    //
    
    public int id(){return id;}

    // Tutto il resto rimane uguale.
    
    /* Native method declaration */
    public native void Setup(byte[] Key);
    public native void PRNG(byte[] Out);
    /* Use static intializer */
    static {
	System.loadLibrary("arc4Lib");
    }
}

