#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
	: Savings_Account {name, balance, int_rate}, withdrawNumber{ 0 } {

}

bool Trust_Account::deposit(double amount) {
	if (amount >= 5000.0) {
		amount += def_bonus;
	}
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
	if (Savings_Account::withdraw(amount)&&withdrawNumber<4) {
		withdrawNumber++;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
	os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
	return os;
}