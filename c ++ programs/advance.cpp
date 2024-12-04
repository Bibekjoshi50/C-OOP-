#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Base class
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

// Derived class for Savings Account
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, double intRate) 
        : Account(accNum, bal), interestRate(intRate) {}

    void applyInterest() {
        balance += balance * interestRate / 100;
    }

    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class for Current Account
class CurrentAccount : public Account {
public:
    CurrentAccount(string accNum, double bal) 
        : Account(accNum, bal) {}

    void withdraw(double amount) override {
        if (amount <= balance + 500) { // Overdraft limit
            balance -= amount;
        } else {
            cout << "Overdraft limit exceeded." << endl;
        }
    }

    void display() const override {
        Account::display();
        cout << "Overdraft Limit: 500" << endl;
    }
};

int main() {
    vector<Account*> accounts;

    // Creating accounts
    accounts.push_back(new SavingsAccount("SA123", 1000.0, 5.0));
    accounts.push_back(new CurrentAccount("CA123", 500.0));

    // Performing operations
    accounts[0]->deposit(200);
    accounts[0]->display();
    cout << endl;

    accounts[1]->withdraw(800);
    accounts[1]->display();
    cout << endl;

    // Applying interest to Savings Account
    dynamic_cast<SavingsAccount*>(accounts[0])->applyInterest();
    accounts[0]->display();

    // File handling: Saving account information to a file
    ofstream outFile("accounts.txt");
    if (outFile.is_open() 
	{
        for (const auto& acc :accounts)
		 {
            outFile << "Account Number: " << acc->accountNumber << endl;
            outFile << "Balance: " << acc->balance << endl;
            if (SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc)) {
                outFile << "Interest Rate: " << sa->interestRate << "%" << endl;
            } else if (CurrentAccount* ca = dynamic_cast<CurrentAccount*>(acc)) {
                outFile << "Overdraft Limit: 500" << endl;
            }
            outFile << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    // Cleaning up
    for (auto& acc : accounts) {
        delete acc;
    }

    return 0;
}

