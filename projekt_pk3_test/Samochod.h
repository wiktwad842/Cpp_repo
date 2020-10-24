#pragma once
#include "Pojazd.h"
class Samochod : public Pojazd {

public:
	virtual void print(ofstream& o) const
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor << "\n";
	}
	virtual void read(ifstream& o)
	{
		o >> id >> marka >> model >> licznik >> kolor;
	}
	virtual bool szukaj_id(int id) const override {
		//cout << "Szukam id samochodu" << endl;
		if (Pojazd::szukaj_id(id)) {
			return true;
		}
		return false;

	}
	virtual ~Samochod() {};
	Samochod(int id, std::string marka, string model, int licznik, string kolor)
		:Pojazd(id, marka, model, licznik, kolor) {

		//	cout << "Konstruktor dla samochodu" << endl;
	}

};

