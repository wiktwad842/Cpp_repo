#include <iostream>
using namespace std;

class Player {
private:
	string name;
	int health;
	int xp;
public:
	void setName(string nameVal) {
		name = nameVal;
	}
	string getName() const{
		return name;
	}
	Player();
	Player(string nameVal);
	Player(string nameVal, int healthVal, int xpVal);
};
Player::Player()
	:Player{ "None",0,0 } {
}
//delegating constructor
Player::Player(string nameVal)
	:Player{ nameVal,0,0 } {

}
//delegating constructor
Player::Player(std::string nameVal, int healthVal, int xpVal)
	: name{ nameVal }, health{ healthVal }, xp{ xpVal }  {
}
void displayPlayerName(const Player& p) {
	cout << p.getName() << endl;
}



	


int main() {

	const Player villain{ "Villain",100,55 };
	Player hero{ "Hero",100,15 };

	displayPlayerName(villain);
	displayPlayerName(hero);

	return 0;
}