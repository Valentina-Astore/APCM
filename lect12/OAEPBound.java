import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.SecureRandom;
import javax.crypto.Cipher;
/**
* RSA example with OAEP Padding and random key generation.
*/
public class OAEPBound {
    private static String digits = "0123456789abcdef";

    public static String toHex(byte[] data, int length) {
	StringBuffer buf = new StringBuffer();
	for (int i = 0; i != length; i++)
	    {
		int v = data[i] & 0xff;
		buf.append(digits.charAt(v >> 4));
		buf.append(digits.charAt(v & 0xf));
	    }
	return buf.toString();
    }
    public static String toHex(byte[] data) {
	return toHex(data, data.length);
    }

    public static void main(
			    String[] args)
	throws Exception
    {

	
	//	byte[] input = new byte[] { 0x00, (byte)0xbe, (byte)0xef };
	
	byte [] input=new byte[6]; // 6 va bene, 7 no. Infatti 7x8+336=392>384
	//= new byte[] { 0x00, (byte)0xbe, (byte)0xef };
	Cipher cipher = Cipher.getInstance("RSA/None/OAEPWithSHA1AndMGF1Padding", "BC");
	SecureRandom random = new SecureRandom();
	// create the keys
	KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA", "BC");
	generator.initialize(384, random); // Qui setto 1024
	KeyPair pair = generator.generateKeyPair();
	Key pubKey = pair.getPublic();
	Key privKey = pair.getPrivate();
	System.out.println("input : " + toHex(input));
	// encryption step
	cipher.init(Cipher.ENCRYPT_MODE, pubKey, random);
	byte[] cipherText = cipher.doFinal(input);
	System.out.println("cipher: " + toHex(cipherText));
	// decryption step
	cipher.init(Cipher.DECRYPT_MODE, privKey);
	byte[] plainText = cipher.doFinal(cipherText);
	System.out.println("plain : " + toHex(plainText));
    }
}
