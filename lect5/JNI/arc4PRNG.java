class arc4PRNG {
    /* Native method declaration */
    public native void runarc4(); //Metodo nativo significa scritto in un linguaggio diverso da java
    /* Use static intializer */
    static {
	System.loadLibrary("arc4Lib");  //stiamo caricando la libreria
    }
    /* Main function calls native method*/
    public static void main(String[] args) {
        new arc4PRNG().runarc4();
    }
}
