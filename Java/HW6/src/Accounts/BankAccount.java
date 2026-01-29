package Accounts;

/**
 * Abstract BankAccount class that does deposits, withdrawals, interest calculation, and monthly processing.
 */
public abstract class BankAccount {
	public double balance; // Double variable for balance
	public int numDep; // integer variable for number of deposits
	public int numWit; // integer variable for number of withdrawals
	public double interest; // Double variable for interest
	public double charges; // Double variable for charges
	
    /**
     * Constructor to initialize balance and interest rate.
     * @param balance Initial balance of the account
     * @param interest Annual interest rate
     */
	public BankAccount(double balance, double interest) {
		this.balance = balance;
		this.numDep = 0;
		this.numWit = 0;
		this.interest = interest;
		this.charges = 0.00;
	}
	
    /**
     * Deposits amount into account and increments deposit count.
     * @param dep Amount to deposit
     * @return Updated balance after deposit
     */
	public double deposit(double dep) {
		balance += dep;
		numDep++;
		return balance;
	}
	
    /**
     * Withdraws amount from account and increments withdrawal count.
     * @param wit Amount to withdraw
     * @return Updated balance after withdrawal
     */
	public double withdraw(double wit) {
		balance -= wit;
		numWit++;
		return balance;
	}
	
    /**
     * Calculates monthly interest and updates the account balance.
     * @return Updated balance after adding monthly interest
     */
	public double calcInterest() {
		double mir = interest / 12; // Monthly interest rate
		double mi = balance * mir; // Monthly interest
		balance += mi;
		return balance;
	}
	
    /**
     * Processes monthly charges, adds interest, and resets counts.
     * @return Final balance after monthly processing
     */
	public double monthlyProcess() {
		balance -= charges;
		calcInterest();
		numDep = 0;
		numWit = 0;
		charges = 0;
		return balance;
	}
	
}
