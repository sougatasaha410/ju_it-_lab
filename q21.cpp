#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class SavingsAccount {
private:
    static int accountCounter; // Static counter to generate unique account numbers
    static double interestRate; // Interest rate for all accounts
    std::string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    SavingsAccount(const std::string& name, double initialBalance) 
        : accountHolderName(name), balance(initialBalance) {
        if (balance < 1000) {
            throw std::invalid_argument("Initial balance must be at least Rs. 1000.");
        }
        accountNumber = ++accountCounter; // Generate unique account number
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1000) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds or minimum balance requirement not met." << std::endl;
        }
    }

    // Method to calculate and deposit interest for one year
    void calculateAndDepositInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
    }

    // Get the current balance
    double getBalance() const {
        return balance;
    }

    // Get the account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Static method to set the interest rate
    static void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Static method to get the interest rate
    static double getInterestRate() {
        return interestRate;
    }

    // Display account details
    void displayAccountDetails() const {
        std::cout << "Account Number: " << accountNumber 
                  << ", Account Holder: " << accountHolderName 
                  << ", Balance: Rs. " << balance << std::endl;
    }
};

// Initialize static members
int SavingsAccount::accountCounter = 0;
double SavingsAccount::interestRate = 4.0; // Default interest rate

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    // Create 100 SavingsAccount objects with random balances
    std::vector<SavingsAccount> accounts;
    for (int i = 0; i < 100; ++i) {
        double initialBalance = 1000 + (rand() % 99001); // Random balance between 1000 and 100000
        accounts.emplace_back("AccountHolder_" + std::to_string(i+1), initialBalance);
    }

    // Calculate and deposit interest for one year for each account
    double totalInterest = 0;
    for (auto& account : accounts) {
        double beforeInterest = account.getBalance();
        account.calculateAndDepositInterest();
        double interestEarned = account.getBalance() - beforeInterest;
        totalInterest += interestEarned;
    }

    // Display account details and total interest to be paid
    std::cout << "Savings Accounts Details after Interest Calculation:\n";
    for (const auto& account : accounts) {
        account.displayAccountDetails();
    }

    std::cout << "\nTotal Interest to be paid to all accounts: Rs. " << totalInterest << std::endl;

    return 0;
}
