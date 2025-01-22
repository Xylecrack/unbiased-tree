#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    static int totalAccounts;
    static BankAccount* accounts[100]; // Array to store up to 100 accounts

public:
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        accounts[totalAccounts] = this;
        totalAccounts++;
    }

    static void deposit(int accNum, double amount) {
        for (int i = 0; i < totalAccounts; i++) {
            if (accounts[i]->accountNumber == accNum) {
                accounts[i]->balance += amount;
                cout << "Deposited " << amount << " to account " << accNum << ". New balance: " << accounts[i]->balance << endl;
                return;
            }
        }
        cout << "Account " << accNum << " not found." << endl;
    }

    static void withdraw(int accNum, double amount) {
        for (int i = 0; i < totalAccounts; i++) {
            if (accounts[i]->accountNumber == accNum) {
                if (accounts[i]->balance >= amount) {
                    accounts[i]->balance -= amount;
                    cout << "Withdrew " << amount << " from account " << accNum << ". New balance: " << accounts[i]->balance << endl;
                } else {
                    cout << "Insufficient funds in account " << accNum << ". Current balance: " << accounts[i]->balance << endl;
                }
                return;
            }
        }
        cout << "Account " << accNum << " not found." << endl;
    }

    static void displayAccountDetails(int accNum) {
        for (int i = 0; i < totalAccounts; i++) {
            if (accounts[i]->accountNumber == accNum) {
                cout << "Account Number: " << accounts[i]->accountNumber << ", Balance: " << accounts[i]->balance << endl;
                return;
            }
        }
        cout << "Account " << accNum << " not found." << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;
BankAccount* BankAccount::accounts[100];

int main() {
    BankAccount acc1(1001, 500.0);
    BankAccount acc2(1002, 1000.0);
    BankAccount acc3(1003, 1500.0);

    BankAccount::deposit(1001, 200.0);
    BankAccount::withdraw(1002, 500.0);
    BankAccount::withdraw(1003, 2000.0); // Insufficient funds

    BankAccount::displayAccountDetails(1001);
    BankAccount::displayAccountDetails(1002);
    BankAccount::displayAccountDetails(1003);

    cout << "Total number of accounts created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}