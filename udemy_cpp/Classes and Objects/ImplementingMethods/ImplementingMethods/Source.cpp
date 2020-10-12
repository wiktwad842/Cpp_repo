#include <iostream>
#include <vector>
using namespace std;

class Account {
	//attributes
private:
	string name;
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
	void setName(string n);
	string getName();

	bool deposit(double amount);
	bool withdraw(double amount);
};

void Account::setName(string n) {
	name = n;
}
string Account::getName() {
	return name;
}
bool Account::deposit(double amount) {
	balance += amount;
	return true;
}
bool Account::withdraw(double amount) {
	if (balance - amount >= 0) {
		balance -= amount;
		return true;
	}
	else
		return false;
}


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