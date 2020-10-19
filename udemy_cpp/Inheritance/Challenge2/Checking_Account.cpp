#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name,double balance)
	:Account{ name,balance } {

}

bool Checking_Account::withdraw(double amount) {
	if (this->balance < def_fee) {
		return false;
	}
	return Account::withdraw(amount+def_fee);

}

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
	os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.def_fee << "$]";
	return os;
}