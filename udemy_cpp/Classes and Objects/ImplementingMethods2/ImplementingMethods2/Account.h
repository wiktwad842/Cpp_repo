#pragma once
#include <string>
class Account {
	//attributes
private:
	std::string name;
	double balance;
	//methods
	//declared inline
public:
	void setBalance(double bal) {
		balance = bal;
	}
	double getBalance() {
		return balance;
	}
	//methods will be declared outside the class declaration
	void setName(std::string n);
	std::string getName();

	bool deposit(double amount);
	bool withdraw(double amount);
};

