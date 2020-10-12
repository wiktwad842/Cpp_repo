#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string name{ "Player" };
	int health;
	int xp;
public:
	void talk(string textToSay) {
		cout << name << " says " << textToSay << endl;
	}
	bool is_dead();
};


int main() {
	Player frank;
	frank.talk("hello there");
	return 0;
}