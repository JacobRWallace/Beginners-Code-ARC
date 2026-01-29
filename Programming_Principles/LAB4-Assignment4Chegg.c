#include <stdio.h>

#define NUM_ACCOUNTS 50
#define MIN_BALANCE 100.00

// Array to hold account balances
double accounts[NUM_ACCOUNTS];

// Number of accounts that are currently open
int num_open_accounts = 0;

// Opens a new account with an initial deposit
void open_account(double initial_deposit) {
    // Check if maximum number of accounts has been reached
    if (num_open_accounts >= NUM_ACCOUNTS) {
        printf("Error: Maximum number of accounts already open.\n");
        return;
    }

    // Check if initial deposit meets minimum balance requirement
    if (initial_deposit < MIN_BALANCE) {
        printf("Error: Initial deposit must be at least $%.2f.\n", MIN_BALANCE);
        return;
    }

    // Assign new account number and add initial deposit to array
    int account_num = 100 + num_open_accounts;
    accounts[num_open_accounts] = initial_deposit;
    num_open_accounts++;

    printf("Account number %d opened with initial deposit of $%.2f.\n", account_num, initial_deposit);
}

// Finds the index of the account in the accounts array given its account number
int find_account(int account_num) {
    // Check if account number is within valid range
    if (account_num < 100 || account_num > 149) {
        printf("Error: Invalid account number.\n");
        return -1;
    }

    // Calculate index of account in accounts array and check if it is open
    int index = account_num - 100;

    if (accounts[index] == -1) {
        printf("Error: Account %d is not open.\n", account_num);
        return -1;
    }

    return index;
}

// Displays the balance of the given account
void balance_inquiry(int account_num) {
    // Find index of account in accounts array and print balance
    int index = find_account(account_num);

    if (index != -1) {
        printf("Account number: %d, Balance: $%.2f.\n", account_num, accounts[index]);
    }
}

// Deposits the given amount into the given account
void deposit(int account_num, double amount) {
    // Find index of account in accounts array and add deposit amount to balance
    int index = find_account(account_num);

    if (index != -1) {
        accounts[index] += amount;
        printf("Account number: %d, New Balance: $%.2f.\n", account_num, accounts[index]);
    }
}

// Withdraws the given amount from the given account
void withdrawal(int account_num, double amount) {
    // Find index of account in accounts array and subtract withdrawal amount from balance
    int index = find_account(account_num);

    if (index != -1) {
        if (accounts[index] < amount) {
            printf("Error: Insufficient funds.\n");
        } else {
            accounts[index] -= amount;
            printf("Account number: %d, New Balance: $%.2f.\n", account_num, accounts[index]);
        }
    }
}

// Closes the given account
void close_account(int account_num) {
    // Find index of account in accounts array and mark as closed
    int index = find_account(account_num);

    if (index != -1) {
        accounts[index] = -1;
        num_open_accounts--;
        printf("Account number %d closed.\n", account_num);
    }
}

// Computes and applies interest to all open accounts
void compute_interest(double rate) {
    for (int i = 0; i < num_open_accounts; i++) {
        accounts[i] += accounts[i] * rate / 100;
    }

    printf("Interest computed and applied to all accounts.\n");
}
// Print all account details
void print_all_accounts() {
    printf("Account Numbers and Balances:\n");

    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        if (accounts[i] != -1) {
            printf("%d: $%.2f\n", 100 + i, accounts[i]);
        }
    }
}
// Close all accounts
void close_all_accounts(){
    printf("Closing all accounts..\n");
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        if (accounts[i] != -1) {
            close_account(100+i);
        }
    }
    printf("Closed all accounts.");
}

int main() {
    // Initialize all accounts to -1.
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        accounts[i] = -1;
    }

    char transaction_type;
    double amount, rate;
    int account_num, index;

    while (1) {
    printf("Transaction type?: ");
    scanf(" %c", &transaction_type);

    switch (transaction_type) {
        case 'O':
        case 'o':
            printf("Initial Deposit?: ");
            scanf("%lf", &amount);
            open_account(amount);
            break;
        case 'B':
        case 'b':
            printf("Account number?: ");
            scanf("%d", &account_num);
            index = find_account(account_num);
            if (index == -1) {
                printf("Account not found\n");
            } else {
                balance_inquiry(account_num);
            }
            break;
        case 'D':
        case 'd':
            printf("Account number?: ");
            scanf("%d", &account_num);
            index = find_account(account_num);
            if (index == -1) {
                printf("Account not found\n");
            } else {
                printf("Amount?: ");
                scanf("%lf", &amount);
                deposit(account_num, amount);
            }
            break;
        case 'W':
        case 'w':
            printf("Account number?: ");
            scanf("%d", &account_num);
            index = find_account(account_num);
            if (index == -1) {
                printf("Account not found\n");
            } else {
                printf("Amount?: ");
                scanf("%lf", &amount);
                withdrawal(account_num, amount);
            }
            break;
        case 'C':
        case 'c':
            printf("Account number?: ");
            scanf("%d", &account_num);
            index = find_account(account_num);
            if (index == -1) {
                printf("Account not found\n");
            } else {
                close_account(account_num);
            }
            break;
        case 'I':
        case 'i':
            printf("Interest rate?: ");
            scanf("%lf", &rate);
            compute_interest(rate);
            break;
        case 'P':
        case 'p':
            print_all_accounts();
            break;
        case 'E':
        case 'e':
            close_all_accounts();
            return 0;
        default:
            printf("Invalid transaction type\n");
            break;
    }
}
return 0;
}
