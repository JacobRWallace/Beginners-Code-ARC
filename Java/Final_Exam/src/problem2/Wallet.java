package problem2;

class Wallet { 
    private double balance; 
  
    //constructor
    public Wallet() { 
        this.balance = 50; 
    } 
    
    
    //function to spend money
    public void spend(double amount) throws IllegalArgumentException, InsufficientFundsException { 
    	
        if (amount <= 0) { 
            throw new IllegalArgumentException("Enter valid amount!"); 
        }
        
        	
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient funds!");
        } 	
        
        
        balance -= amount; 
        System.out.println( "$" + amount + " was spent. Remaining balance left is $" + balance); 
        
    }

    
    
    //getter fucntion 
    public double getBalance() {
        return balance;
    }
  
}


