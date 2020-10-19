#pragma once
#include <string>
#include <vector>
using namespace std;




class Account
{
public:
	double balance;
	string name;
	void deposit(double amount);
	void withdraw(double amount);
	Account();
	~Account();
};

