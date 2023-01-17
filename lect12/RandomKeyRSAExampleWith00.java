import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.SecureRandom;
import javax.crypto.Cipher;
import java.security.spec.RSAKeyGenParameterSpec;
/**
* RSA example with random key generation.
*/
public class RandomKeyRSAExampleWith00
{
    public static void main(String[] args) throws Exception
    {
	//	byte[] input = new byte[] { (byte)0xbe, (byte)0xef }; //First Example
	byte[] input = new byte[] {0x00, (byte)0xbe, (byte)0xef }; // Second Example
	
	Cipher cipher = Cipher.getInstance("RSA/None/NoPadding", "BC");
	SecureRandom random = Utils.createFixedRandom();
	// create the keys
	KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA", "BC");
	generator.initialize(256, random); //length, source of randomness
	//generator.initialize(new RSAKeyGenParameterSpec(256, RSAKeyGenParameterSpec.F0), random); //Second example ^3
	KeyPair pair = generator.generateKeyPair(); //Private and public



	Key pubKey = pair.getPublic();
	Key privKey = pair.getPrivate();
	System.out.println("input : " + Utils.toHex(input));
	// encryption step
	cipher.init(Cipher.ENCRYPT_MODE, pubKey, random);
	byte[] cipherText = cipher.doFinal(input);
	System.out.println("cipher: " + Utils.toHex(cipherText));
	// decryption step
	cipher.init(Cipher.DECRYPT_MODE, privKey);
	byte[] plainText = cipher.doFinal(cipherText);
	System.out.println("plain : " + Utils.toHex(plainText));
    }
}
