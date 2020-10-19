#pragma once
#include "Account.h"
class SavingsAccount :
    public Account
{
public:
    double intRate;
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double amount);
    void withdraw(double amount);
};

