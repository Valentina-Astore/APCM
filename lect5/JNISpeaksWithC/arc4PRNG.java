

class arc4PRNG {
    public static void PrintOut(byte[] Out){
	System.out.println("----");
	for(int i=0;i<Out.length;i++)
	    System.out.println(String.format("%02X",Out[i]));
    }
    public static void main(String[] args) {
	// Questa volta gestiamo l'i/o  da Java
	byte Key[]={'p','i','p','p','o'};
	byte Out[];
	Out=new byte [15];
	//

	// Creiamo il nostro oggetto
	arc4JNI arc4A=new arc4JNI();
	//arc4PRNG Funziona solo con un unico oggetto!!
	arc4JNI arc4B=new arc4JNI();

	arc4A.Setup(Key);
	arc4A.PRNG(Out);
	System.out.println("Primi 15 byte di A");
	PrintOut(Out);

	System.out.println("SetUp di arc4B");
	arc4B.Setup(Key);

	System.out.println("Altri 15 byte di A");//il setup precedente ci ha resettato lo stato -> ripartirà da capo
	arc4A.PRNG(Out);
	PrintOut(Out);
	

    }
}
