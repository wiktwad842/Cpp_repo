#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Osoba {
private:
	int PESEL;
	string nazwisko;
	string imie;
	string dataUrodzenia;
};

class Pojazd {
protected:
	int id;
	string marka;
	string kolor;
	string licznik;
};

class Samochod : public Pojazd {
protected:

};





class Relacja {
private:
	int PESEL;
	int id;
};





int main() {
	vector<Osoba> bazaOsob;
	vector<Samochod> bazaSamochodow;
	vector<Relacja> bazaRelacji;
}