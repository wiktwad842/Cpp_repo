#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
using namespace std;

int main() { 
	
	cout << "\n=== Account ==============================" << endl;
	Account acc{};
	acc.deposit(2000.0);
	acc.withdraw(500.0);
	cout << endl;
	Account* pAcc{ nullptr };
	pAcc = new Account();
	pAcc->deposit(1000.0);
	pAcc->withdraw(500.0);
	delete pAcc;

	cout << "\n=== Savings Account ==============================" << endl;
	SavingsAccount savacc{};
	savacc.deposit(2000.0);
	savacc.withdraw(500.0);
	cout << endl;
	SavingsAccount* psavAcc{ nullptr };
	psavAcc = new SavingsAccount();
	psavAcc->deposit(1000.0);
	psavAcc->withdraw(500.0);
	delete psavAcc;
	
	
	return 0;
}