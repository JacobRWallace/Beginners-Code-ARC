package Accounts;

/**
 * Demonstrates SavingsAccount class by performing deposits, withdrawals, interest calculation, and monthly processing.
 */
public class BankAccount_Demo {
	public static void main(String[] args) {
		
		// Creates SavingsAccount object called "savings" to initialize balance and interest rate
		SavingsAccount savings = new SavingsAccount(500.0, 0.04);
		
		System.out.println("Initial Balance: $" + savings.balance);
        System.out.println("After deposit of $10: $" + savings.deposit(10));
        System.out.println("After withdrawal of $20: $" + savings.withdraw(20));
        System.out.println("After calculating interest: $" + savings.calcInterest());
        
        System.out.println("1st withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("2nd withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("3rd withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("4th withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("5th withdrawal of $5: $" + savings.withdraw(5)); // Extra services charges apply now!
        System.out.println("6th withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("7th withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("8th withdrawal of $5: $" + savings.withdraw(5));
        System.out.println("9th withdrawal of $435: $" + savings.withdraw(435));
        System.out.println("10th withdrawal of $5: $" + savings.withdraw(5));

        System.out.println("After monthly processing: $" + savings.monthlyProcess()); // Final balance with charges
        
        // Additional tests for reactivation
        System.out.println("Deposit of $2: $" + savings.deposit(2));
        System.out.println("Deposit of $10: $" + savings.deposit(10));
        System.out.println("Deposit of $999: $" + savings.deposit(999));
	}
}
