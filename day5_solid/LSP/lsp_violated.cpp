#include <iostream>
using namespace std;

// LSP --> Liskov Substitution Principle
class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "deposited in your saving bank account" << endl;
    }

    void withdraw(double amount)
    {

        if (balance >= amount)
        {
            balance -= amount;
            cout << "withdrawn successfully from your saving account" << endl;
        }
        else
        {
            cout << "insufficient balance : saving" << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "deposited in your current bank account" << endl;
    }

    void withdraw(double amount)
    {

        if (balance >= amount)
        {
            balance -= amount;
            cout << "withdrawn successfully from your current account" << endl;
        }
        else
        {
            cout << "insufficient balance : current" << endl;
        }
    }
};

class FDAccount : public Account
{
private:
    double balance;

public:
    FDAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "deposited in your FD account" << endl;
    }

    void withdraw(double amount)
    {
        throw logic_error("withdrawl is not allowed in FD Account."); //--> this is the violation of LSP
    }
};

int main()
{

    Account *acct1 = new SavingAccount(); // --> Account is substituted by SavingAccount => followed LSP
    acct1->deposit(100);
    acct1->withdraw(50);

    Account *acct2 = new FDAccount(); // --> Account is not substituted by FDAccount => violated LSP
    acct2->deposit(400);
    acct2->withdraw(40);

    return 0;
}