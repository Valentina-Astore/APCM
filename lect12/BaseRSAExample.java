import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.RSAPrivateKeySpec;
import java.security.spec.RSAPublicKeySpec;
import javax.crypto.Cipher;
/**
* Basic RSA example.
*/
public class BaseRSAExample {
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
    



    public static void main(String[] args) throws Exception {
	byte[] input = new byte[] { (byte)0xbe, (byte)0xef };
	Cipher cipher = Cipher.getInstance("RSA/None/NoPadding", "BC");//"BC" sta per il provider: Bpuncy Castle
	// create the keys
	KeyFactory keyFactory = KeyFactory.getInstance("RSA", "BC");//fai una chiave per rsa con il provider BC
	RSAPublicKeySpec pubKeySpec = new RSAPublicKeySpec(new BigInteger("d46f473a2d746537de2056ae3092c451", 16),
							   new BigInteger("11", 16));
	RSAPrivateKeySpec privKeySpec = new RSAPrivateKeySpec(new BigInteger("d46f473a2d746537de2056ae3092c451", 16), 
							      new BigInteger("57791d5430d593164082036ad8b29fb1", 16));
	RSAPublicKey pubKey = (RSAPublicKey)keyFactory.generatePublic(pubKeySpec);
	RSAPrivateKey privKey = (RSAPrivateKey)keyFactory.generatePrivate(privKeySpec);
	System.out.println("input : " + toHex(input));
	// encryption step
	cipher.init(Cipher.ENCRYPT_MODE, pubKey);
	byte[] cipherText = cipher.doFinal(input);
	System.out.println("cipher: " + toHex(cipherText));
	// decryption step
	cipher.init(Cipher.DECRYPT_MODE, privKey);
	byte[] plainText = cipher.doFinal(cipherText);
	System.out.println("plain : " + toHex(plainText));
    }
}
