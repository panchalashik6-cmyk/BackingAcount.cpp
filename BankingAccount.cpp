#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal = 0.0)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    virtual ~BankAccount() {}

    void deposit(double amount) 

    { 
        balance += amount; 
    }

    virtual void withdraw(double amount) {

        if (amount <= balance) balance -= amount;
        else cout << "Insufficient balance\n";
    }

    double getBalance() const
    
    { return balance;
    
    }

    virtual void calculateInterest() {

    }

    virtual void displayAccount() const {
        cout << "Acc No: " << accountNumber
             << " Name: " << accountHolderName
             << " Balance: " << balance << endl;
    }
};


class SavingsAccount : public BankAccount {
    double interestRate;  

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100.0;
        balance += interest;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) balance -= amount;
        else cout << "Overdraft limit exceeded\n";
    }
};

class FixedDepositAccount : public BankAccount {
    int durationMonths;    
    double interestRate;  

public:
    FixedDepositAccount(int accNo, string name, double bal,
                        int months, double rate)
        : BankAccount(accNo, name, bal),
          durationMonths(months), interestRate(rate) {}

    void calculateInterest() override {
        double years = durationMonths / 12.0;
        double interest = balance * interestRate * years / 100.0;
        balance += interest;
    }
};

int main() {
    SavingsAccount     s1(101, "ashik",   10000, 5.0);
    CheckingAccount    c1(102, "harshil",   5000, 2000);
    FixedDepositAccount f1(103, "alpesh", 20000, 12, 7.0);

    BankAccount* acc[3] = { &s1, &c1, &f1 };

    acc[0]->deposit(2000);    
    acc[1]->withdraw(6000);      
    acc[2]->calculateInterest();  

    cout << "\nAccount Details:\n";
    for (int i = 0; i < 3; ++i) acc[i]->displayAccount();

    return 0;
}
