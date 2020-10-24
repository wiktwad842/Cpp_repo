#pragma once
#include "Pojazd.h"
class Bus : public Pojazd
{

protected:
	double ladownosc;

public:
	virtual void print(ofstream& o) const
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor << ", ladownosc: " << this->ladownosc << "\n";
	}
	virtual void read(ifstream& o)
	{
		o >> id >> marka >> model >> licznik >> kolor >> ladownosc;
	}
	virtual bool szukaj_id(int id) const {
		//cout << "Szukam id busa" << endl;
		if (Pojazd::szukaj_id(id)) {
			return true;
		}
		return false;
	}
	virtual ~Bus() {};
	Bus(int id, string marka, string model, int licznik, string kolor, double ladownosc)
		:Pojazd(id, marka, model, licznik, kolor), ladownosc{ ladownosc }{

	}

};

