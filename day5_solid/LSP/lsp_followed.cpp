#include <iostream>
using namespace std;

class DepositedAccount
{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawlAccount : public DepositedAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawlAccount
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

class CurrentAccount : public WithdrawlAccount
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

class FDAccount : public DepositedAccount
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
    WithdrawlAccount* acct1 = new SavingAccount();
    acct1->deposit(100);
    acct1->withdraw(50);

    WithdrawlAccount* acct2 = new CurrentAccount();
    acct2->deposit(100);
    acct2->withdraw(50);

    DepositedAccount* acct3 = new FDAccount();
    acct3->deposit(100);
    
    return 0;
}