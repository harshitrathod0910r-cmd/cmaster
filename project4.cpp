#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    BankAccount(int acc, string name, double bal) {
        accountNumber = acc;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) {    
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    double getBalance() { return balance; }

    virtual void displayAccountInfo() {
        cout << "\nAccount No: " << accountNumber;
        cout << "\nHolder Name: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }
};
class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int acc, string name, double bal, double rate)
        : BankAccount(acc, name, bal) {
        interestRate = rate;
    }
    double calculateInterest() { return balance * interestRate / 100; }
};
class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(int acc, string name, double bal, double limit)
        : BankAccount(acc, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit)
            balance -= amount;
        else
            cout << "Overdraft Limit Exceeded!" << endl;
    }
};
class FixedDepositAccount : public BankAccount {
    int term;
public:
    FixedDepositAccount(int acc, string name, double bal, int t)
        : BankAccount(acc, name, bal) {
        term = t;
    }
    double calculateInterest() { return balance * 0.08 * term; }
};

int main() {
    SavingsAccount sa(101, "Alpesh", 5000, 5);
    CheckingAccount ca(102, "Meet", 3000, 1000);
    FixedDepositAccount fda(103, "Raj", 10000, 12);

    int choice;
    double amount;
    while (true) {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit (Savings)\n";
        cout << "2. Withdraw (Savings)\n";
        cout << "3. Withdraw (Checking)\n";
        cout << "4. Check FD Interest\n";
        cout << "5. Display Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            sa.deposit(amount);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            sa.withdraw(amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            ca.withdraw(amount);
            break;

        case 4:
            cout << "FD Interest: " << fda.calculateInterest() << endl;
            break;

        case 5:
            sa.displayAccountInfo();
            ca.displayAccountInfo();
            fda.displayAccountInfo();
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}