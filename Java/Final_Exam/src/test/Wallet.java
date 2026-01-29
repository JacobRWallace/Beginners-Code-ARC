// Custom exception class InsufficientFundsException
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

// Wallet class
class Wallet {
    private double balance;

    // Constructor to initialize the balance
    public Wallet() {
        this.balance = 50.0; // Starting balance
    }

    // Method to spend money
    public void spend(double amount) throws IllegalArgumentException, InsufficientFundsException {
        if (amount <= 0) {
            throw new IllegalArgumentException("Spend amount must be greater than zero.");
        }
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient funds. Current balance: " + balance);
        }
        balance -= amount;
        System.out.println("Successfully spent: $" + amount + ". Remaining balance: $" + balance);
    }

    // Getter for balance
    public double getBalance() {
        return balance;
    }
}

// Demo class WalletDemo
public class WalletDemo {
    public static void main(String[] args) {
        Wallet myWallet = new Wallet();

        // Try spending -50 (negative amount)
        try {
            System.out.println("Attempting to spend -50...");
            myWallet.spend(-50);
        } catch (IllegalArgumentException e) {
            System.out.println("Exception: " + e.getMessage());
        } catch (InsufficientFundsException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        // Try spending 100 (more than the balance)
        try {
            System.out.println("Attempting to spend 100...");
            myWallet.spend(100);
        } catch (IllegalArgumentException e) {
            System.out.println("Exception: " + e.getMessage());
        } catch (InsufficientFundsException e) {
            System.out.println("Exception: " + e.getMessage());
        }

        // Display the remaining balance
        System.out.println("Final wallet balance: $" + myWallet.getBalance());
    }
}
