#include <iostream>
using namespace std;

class DepositedAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawlAccount : DepositedAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : WithdrawlAccount
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
        cout << "desposited successfully in saving account" << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "amount withdrwn successfully from saving account" << endl;
        }
        else
        {
            cout << "insufficient balance" << endl;
        }
    }
};

class CurrentAccount : WithdrawlAccount
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
        cout << "desposited successfully in current account" << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "amount withdrwn successfully from current account" << endl;
        }
        else
        {
            cout << "insufficient balance" << endl;
        }
    }
};

class FDAccount : DepositedAccount
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
        cout << "deposited successfully in FD account" << endl;
    }
};

int main()
{

    return 0;
}