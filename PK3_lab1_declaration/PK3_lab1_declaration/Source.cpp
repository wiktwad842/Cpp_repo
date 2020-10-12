#include <iostream>
#include <string>
using namespace std;
class CBudynek {
private:
	int rok;
	double wys;
	char* nazwa;
public:
	int getSize(CBudynek budynek) {
		int temp = sizeof(*nazwa);
		return temp;
	}
	void wypisz() {
		cout << "Rok: " << this->rok << endl;
		cout << "wys: " << this->wys << endl;
		cout << "nazwa: " << this->nazwa << endl;
	}

	//Player()
	//	:Player{ "None",0,0 } {
	//}
	////delegating constructor
	//Player(string nameVal)
	//	:Player{ nameVal,0,0 } {

	//}
	////delegating constructor
	//Player(std::string nameVal, int healthVal, int xpVal)
	//	: name{ nameVal }, health{ healthVal }, xp{ xpVal }  {
	//}



	CBudynek(double wysVal,char*nazwaVal)
		: CBudynek{2015,wysVal,nazwaVal}{
	}

	CBudynek() {
		char* p = new char[] {"Eiffla"};
		this->nazwa = p;
		this->rok=1887;
		this->wys = 324.2;
		cout << "Konstruktor bezargumentowy" << endl;
	}
		 


	CBudynek(int rokVal,double wysVal,char* nazwaVal)
		: rok{ rokVal }, wys{ wysVal },nazwa{ nazwaVal }{
		cout << "3-arg constructor called" << endl;
	}

	~CBudynek() {
		cout << "Destruktor wywo³any dla: " << nazwa << endl;
	}
		
};

int main() {
	char* p = new char[] {"Eiffla"};
	char* q = new char[] {"Palac kultury"};
	//CBudynek budynek(1887, 324.2, p);

	//budynek.wypisz();
	
	CBudynek ob1(1995, 300.0, q);

	ob1.wypisz();

	CBudynek ob2 = ob1;

	ob2.wypisz();
	return 0;
}