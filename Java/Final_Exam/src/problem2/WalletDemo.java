package problem2;

import java.util.Scanner;

import problem2.InsufficientFundsException;
import problem2.Wallet;
 	
public class WalletDemo { 
    public static void main(String[] args) { 
    	
    	Scanner scanner = new Scanner(System.in);
    	
    	// create wallet object .
        Wallet myWallet = new Wallet(); 
        
        System.out.println("Balance: $" + myWallet.getBalance());
        
        System.out.println("Enter spending amount 1 (-50):");
        int input = scanner.nextInt();
        
         // try to spend -50.
        try { 
            myWallet.spend(input); 
            } 
        
        catch (IllegalArgumentException error) { 
            System.out.println(error.getMessage()); 
        } 
        	
        catch (InsufficientFundsException error) { 
        	System.out.println(error.getMessage());
        } 	
        
        System.out.println("Enter spending amount 2 (100):");
        int input1 = scanner.nextInt();
        
        // try to spend over 100.
        try { 
        	myWallet.spend(input1); 
        	}
        
        catch (IllegalArgumentException error) { 
            System.out.println(error.getMessage()); 
        } 
        	
        catch (InsufficientFundsException error) { 
        	System.out.println(error.getMessage());
        } 	
        
    } 
   
    
}