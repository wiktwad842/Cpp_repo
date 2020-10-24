#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Pojazd {
	friend  std::ofstream& operator<<(std::ofstream& os, const Pojazd& pojazd);
	//friend  std::ifstream& operator>>(std::ifstream& os, Pojazd& pojazd);
protected:
	int id;
	string marka;
	string model;
	int licznik;
	string kolor;
public:
	virtual void print(ofstream& o) const
	{
	}
	virtual void read(ifstream& o)
	{
	}
	virtual bool szukaj_id(int id) const {
		if (this->id == id) {
			return true;
		}
		return false;
	}
	virtual ~Pojazd() {

	};
	Pojazd(int id, string marka, string model, int licznik, string kolor)
		:id{ id }, marka{ marka }, model{ model }, licznik{ licznik }, kolor{ kolor }{
		//	cout << "Konstruktor dla pojazdu" << endl;
	}

	int getId() {
		return this->id;
	}
	string getMarka() {
		return this->marka;
	}
};

