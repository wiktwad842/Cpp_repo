#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount() 
	:intRate{3.0} {

}

SavingsAccount::~SavingsAccount() {

}

void SavingsAccount::deposit(double amount) {
	std::cout << "Savings account deposit called with " << amount << std::endl;
}

void SavingsAccount::withdraw(double amount) {
	std::cout << "Savings account withdraw called with " << amount << std::endl;
}