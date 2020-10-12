#include <iostream>
#include <string>

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
	string getName() {
		return name;
	}
	Player() {
		name = "none";
		health = 100;
		xp = 3;
	}
	Player(string nameVal, int healthVal, int xpVal) {
		name = nameVal;
		health = healthVal;
		xp = xpVal;
	}
};

int main() {
	Player frank;

	return 0;
}