#pragma once
#include <fstream>
using namespace std;
class Relacja {
	friend  std::ifstream& operator>>(std::ifstream& os, Relacja& relacja);
private:
	string PESEL;
	int id;
public:
	Relacja()
		:PESEL{ "" }, id{ -1 } {}
	Relacja(string PESEL, int id)
		: PESEL{ PESEL }, id{ id } {
	}
	string szukajPESELDlaId(int id) {
		if (this->id == id) {
			return this->PESEL;
		}
		return "";
	}

	int szukajIdDlaPESEL(string PESEL) {
		if (this->PESEL == PESEL) {
			return this->id;
		}
		return 0;
	}
	~Relacja() {}


};


