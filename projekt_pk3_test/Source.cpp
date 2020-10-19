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
class Samochod {
private:
	int id;
	string marka;
	string kolor;
	string licznik;
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