#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() {
        accountNumber = "";
        accountHolderName = "";
        balance = 0.0;
    }

    void createAccount(string accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "No interest for base account." << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Interest (Savings): " << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    void setOverdraftLimit(double limit) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void calculateInterest() override {
        cout << "No interest for Checking Account." << endl;
    }
};

class FixedDepositAccount : public BankAccount {
private:
    int term;

public:
    void setTerm(int t) {
        term = t;
    }

    void calculateInterest() override {
        double rate = 5.0;
        double interest = balance * rate * term / (100 * 12);
        cout << "Interest (Fixed Deposit): " << interest << endl;
    }
};

int main() {
    int choice;
    SavingsAccount savings;
    CheckingAccount checking;
    FixedDepositAccount fixed;
    bool savingsCreated = false, checkingCreated = false, fixedCreated = false;

    do {
        cout << "\n===== BANKING SYSTEM MENU =====" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Display Account Info" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string accNo, name;
        double bal, amount, rate, limit;
        int term;

        switch (choice) {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Holder Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            savings.createAccount(accNo, name, bal);
            savings.setInterestRate(rate);
            savingsCreated = true;
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Holder Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            checking.createAccount(accNo, name, bal);
            checking.setOverdraftLimit(limit);
            checkingCreated = true;
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Holder Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Term (months): ";
            cin >> term;
            fixed.createAccount(accNo, name, bal);
            fixed.setTerm(term);
            fixedCreated = true;
            break;

        case 4:
            cout << "Deposit to:\n1. Savings\n2. Checking\n3. Fixed: ";
            cin >> choice;
            cout << "Enter amount: ";
            cin >> amount;
            if (choice == 1 && savingsCreated) savings.deposit(amount);
            else if (choice == 2 && checkingCreated) checking.deposit(amount);
            else if (choice == 3 && fixedCreated) fixed.deposit(amount);
            else cout << "Account not created!" << endl;
            break;

        case 5:
            cout << "Withdraw from:\n1. Savings\n2. Checking\n3. Fixed: ";
            cin >> choice;
            cout << "Enter amount: ";
            cin >> amount;
            if (choice == 1 && savingsCreated) savings.withdraw(amount);
            else if (choice == 2 && checkingCreated) checking.withdraw(amount);
            else if (choice == 3 && fixedCreated) fixed.withdraw(amount);
            else cout << "Account not created!" << endl;
            break;

        case 6:
            cout << "Display which account?\n1. Savings\n2. Checking\n3. Fixed: ";
            cin >> choice;
            if (choice == 1 && savingsCreated) savings.displayAccountInfo();
            else if (choice == 2 && checkingCreated) checking.displayAccountInfo();
            else if (choice == 3 && fixedCreated) fixed.displayAccountInfo();
            else cout << "Account not created!" << endl;
            break;

        case 7:
            cout << "Calculate interest for:\n1. Savings\n2. Checking\n3. Fixed: ";
            cin >> choice;
            if (choice == 1 && savingsCreated) savings.calculateInterest();
            else if (choice == 2 && checkingCreated) checking.calculateInterest();
            else if (choice == 3 && fixedCreated) fixed.calculateInterest();
            else cout << "Account not created!" << endl;
            break;

        case 0:
            cout << "Thank you for using our banking system." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}