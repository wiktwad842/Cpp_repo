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
	
	

	Player()
		:Player{ "None",0,0 } {
		} 
	//delegating constructor
	Player(string nameVal)
		:Player{ nameVal,0,0 } {

	}
	//delegating constructor
	Player(std::string nameVal, int healthVal, int xpVal)
		: name{ nameVal }, health{ healthVal }, xp{ xpVal }  {
	}



	/*Player()
		: name{ "None" }, health{ 0 }, xp{ 0 }  {

	}
	Player(std::string nameVal)
		: name{ nameVal }, health{ 0 }, xp{ 0 }  {

	}
	Player(std::string nameVal,int healthVal,int xpVal)
		: name{ nameVal }, health{ healthVal }, xp{ xpVal }  {

	}*/
};

int main() {
	Player frank;

	return 0;
}