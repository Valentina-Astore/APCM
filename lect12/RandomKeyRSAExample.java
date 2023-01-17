import java.security.MessageDigest;

import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.SecureRandom;
import javax.crypto.Cipher;
import java.security.spec.RSAKeyGenParameterSpec;
/**
* RSA example with random key generation.
*/
public class RandomKeyRSAExample{
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
    /*
    
    private static class FixedRand extends SecureRandom {
	MessageDigest sha;
	byte[] state;
	FixedRand() {
	    try
		{
		    this.sha = MessageDigest.getInstance("SHA-1", "BC");
		    this.state = sha.digest();
		}
	    catch (Exception e)
		{
		    throw new RuntimeException("can't find SHA-1!");
		}
	}
    }

    */
    public static void main(String[] args) throws Exception {
	byte[] input = new byte[] { (byte)0xbe, (byte)0xef }; //First Example
	//	byte[] input = new byte[] {0x00, (byte)0xbe, (byte)0xef }; // Second Example
	//	byte[] input = new byte[] {(byte)0xbe, (byte)0xef }; // Second Example
	Cipher cipher = Cipher.getInstance("RSA/None/NoPadding", "BC");

	//	SecureRandom random = new FixedRand();
	SecureRandom random = new SecureRandom();
	// create the keys
	KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA", "BC");
	generator.initialize(256, random); //length, source of randomness
	//generator.initialize(new RSAKeyGenParameterSpec(256, RSAKeyGenParameterSpec.F0), random); //Second example ^3
	KeyPair pair = generator.generateKeyPair(); //Private and public



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
