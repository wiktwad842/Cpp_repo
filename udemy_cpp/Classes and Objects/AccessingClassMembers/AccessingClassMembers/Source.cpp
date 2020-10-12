#include <iostream>
#include <vector>
using namespace std;

class Player {
	//attributes
public:
	string name;
	int health;
	int xp;
	//methods
	void talk(string text_to_say) {
		cout << name << " says " << text_to_say << endl;
	}
	bool isDead();

};
class Account {
	//attributes
public:
	string name;
	double balance;
	//methods
	bool deposit(double bal) {
		balance += bal;
		cout << "In deposit" << endl;
		return true;
	}
	bool withdraw(double bal) {
		balance -= bal;
		cout << "In withdrawal" << endl;
		return true;
	}
};

int main() {

	Account frank_account;
	
	frank_account.name = "Frank's account";
	frank_account.balance = 5000.0;

	frank_account.deposit(1000.0);
	frank_account.withdraw(500.0);

	Player frank;
	Player hero;

	frank.name = "Frank";
	frank.health = 100;
	frank.xp = 12;
	frank.talk("Hi there");
	
	Player* enemy = new Player;
	(*enemy).name = "Enemy";
	(*enemy).health = 100;
	enemy->xp = 15;
	enemy->talk("I will destroy you");


	return 0;
}