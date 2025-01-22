#include <iostream>

using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    double rateOfInterest;
    static int accountCounter;

public:
    Account(double balance, double rateOfInterest)
    {
        this->balance = balance;
        this->rateOfInterest = rateOfInterest;
        accountNumber = ++accountCounter;
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void addInterest() = 0;
    virtual void viewDetails() = 0;
};

int Account::accountCounter = 1000;

class SavingAcc : public Account
{
private:
    static int threshold;

public:
    SavingAcc(double balance, double rateOfInterest) : Account(balance, rateOfInterest) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " to Saving Account." << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= threshold)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from Saving Account." << endl;
        }
        else
        {
            cout << "Insufficient balance or below threshold." << endl;
        }
    }

    void addInterest() override
    {
        balance += balance * rateOfInterest;
        cout << "Interest added to Saving Account." << endl;
    }

    void viewDetails() override
    {
        cout << "Saving Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Rate of Interest: " << rateOfInterest << endl;
    }
};

int SavingAcc::threshold = 1000;

class FlexiFixedDepositAcc : public Account
{
private:
    static int threshold;

public:
    FlexiFixedDepositAcc(double balance, double rateOfInterest) : Account(balance, rateOfInterest) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " to Flexi Fixed Deposit Account." << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= threshold)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from Flexi Fixed Deposit Account." << endl;
        }
        else
        {
            cout << "Insufficient balance in Flexi Fixed Deposit Account." << endl;
        }
    }

    void addInterest() override
    {
        balance += balance * rateOfInterest;
        cout << "Interest added to Flexi Fixed Deposit Account." << endl;
    }

    void viewDetails() override
    {
        cout << "Flexi Fixed Deposit Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Rate of Interest: " << rateOfInterest << endl;
    }
};

int FlexiFixedDepositAcc::threshold = 1000;

int main()
{
    SavingAcc s(1000, 0.05);
    FlexiFixedDepositAcc f(1000, 0.07);

    int choice;
    double amount;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Deposit to Saving Account" << endl;
        cout << "2. Deposit to Flexi Fixed Deposit Account" << endl;
        cout << "3. Withdraw from Saving Account" << endl;
        cout << "4. Transfer to Saving Account" << endl;
        cout << "5. Transfer to Flexi Fixed Deposit Account" << endl;
        cout << "6. Add Interest" << endl;
        cout << "7. View Details" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposit to Saving Account: ";
            cin >> amount;
            s.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to deposit to Flexi Fixed Deposit Account: ";
            cin >> amount;
            f.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw from Saving Account: ";
            cin >> amount;
            s.withdraw(amount);
            break;
        case 4:
            cout << "Enter amount to transfer from Flexi Fixed Deposit to Saving Account: ";
            cin >> amount;
            f.withdraw(amount);
            s.deposit(amount);
            break;
        case 5:
            cout << "Enter amount to transfer from Saving Account to Flexi Fixed Deposit Account: ";
            cin >> amount;
            s.withdraw(amount);
            f.deposit(amount);
            break;
        case 6:
            s.addInterest();
            f.addInterest();
            break;
        case 7:
            s.viewDetails();
            f.viewDetails();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
