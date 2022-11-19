public class arc4JNI {
    /* 
       Definiamo due metodi nativi:
       Setup
       PRNG
    */
    public native void Setup(byte[] Key);
    public native void PRNG(byte[] Out);
    /* Use static intializer */
    static {
	System.loadLibrary("arc4Lib");
    }
}

