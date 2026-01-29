package Accounts;

/**
 * Represents a SavingsAccount that extends BankAccount.
 * Adds an active/inactive status based on balance.
 */
public class SavingsAccount extends BankAccount {
	
	public boolean status; // Boolean variable for active account or not.
	
	/**
     * Constructor to initialize balance and interest.
     * @param balance Initial balance of the account
     * @param interest Annual interest rate
     */
	public SavingsAccount(double balance, double interest) {
		super(balance, interest);
		status = (balance >= 25);
	}
	
    /**
     * Withdraws amount if account is active.
     * Updates account status if balance is below $25.
     * @param amount Amount to withdraw
     * @return Updated balance after withdrawal
     */
	public double withdraw(double amount) {
		if(status) {
			super.withdraw(amount);
			if(balance <= 25) {
				status = false;}
			}
		else {
			System.out.println("Withdrawal denied. Below $25.00! Account inactive. ");}
		return balance;
	}
	
	
	 /**
     * Deposits amount and activates account if balance is over $25.
     * @param amount Amount to deposit
     * @return Updated balance after deposit
     */
	public double deposit(double amount) {
		if(status || ((balance + amount) > 25)) {
			super.deposit(amount);
			if(balance > 25)
				status = true;
			}
		else {
			System.out.println("Deposit denied. Below $25.00! Account inactive. ");}
		return balance;
	}
	
    /**
     * Processes monthly transactions and applies additional charges.
     * Updates status based on balance after monthly charges.
     * @return Final balance after monthly processing
     */
	public double monthlyProcess() {
		if(numWit > 4)
			charges += (numWit - 4);
		super.monthlyProcess(); // do the calculations after updating new charges value.
		if(balance < 25) status = false;
		return balance;
	}
}
