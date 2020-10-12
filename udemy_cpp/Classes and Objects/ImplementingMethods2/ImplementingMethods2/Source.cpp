#include <iostream>
#include <vector>
using namespace std;
#include "Account.h"


int main() {

	Account frank_account;
	frank_account.setName("Frank's account");
	frank_account.setBalance(1000.0);

	if (frank_account.deposit(200.0))
		cout << "Deposit OK" << endl;
	else
		cout << "Deposit not allowed" << endl;

	if (frank_account.withdraw(500.0))
		cout << "Withdrawal OK" << endl;
	else
		cout << "Not sufficent funds" << endl;

	if (frank_account.withdraw(1500.0))
		cout << "Withdrawal OK" << endl;
	else
		cout << "Not sufficent funds" << endl;




	return 0;
}