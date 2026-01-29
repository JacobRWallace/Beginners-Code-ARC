package ClassWork112224;

import javax.crypto.*;

public class AESExample {
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        String plaintext = "Hi from CS-2365 section1";
        System.out.println(plaintext);

        // Generate Secret Key
        SecretKey secretKey = KeyGenerator.getInstance("AES").generateKey();

        Cipher cipher = Cipher.getInstance("AES");

        // Encrypt
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plaintext.getBytes());
        String encryptedText = new String(encryptedBytes);
        System.out.println(encryptedText);

        // Decrypt
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println(decryptedText);
    }
}
