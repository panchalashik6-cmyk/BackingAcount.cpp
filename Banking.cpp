#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    int accNo;
    float balance;

public:
    BankAccount(string n, int a, float b) {  
        name = n;
        accNo = a;
        balance = b;
    }

    void deposit(float amt) {
        balance += amt;
        cout << "Amount Deposited" << endl;
    }

    void withdraw(float amt) {
        if (amt <= balance) {
            balance -= amt;
            cout << "Amount Withdrawn" << endl;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account No.: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    string name;
    int acc;
    float bal, amt;
    int choice;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Account No: ";
    cin >> acc;
    cout << "Enter Opening Balance: ";
    cin >> bal;

    BankAccount obj(name, acc, bal);

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amt;
            obj.deposit(amt);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amt;
            obj.withdraw(amt);
            break;

        case 3:
            obj.display();
            break;

        case 4:
            cout << "Thank You!";
            break;

        default:
            cout << "Invalid Choice!";
        }
    } while (choice != 4);

    return 0;
}