#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Pojazd {
	friend  std::ofstream& operator<<(std::ofstream& os, const Pojazd& account);
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
	virtual bool szukaj_id(const vector<Pojazd*>& bazaPojazdow,int id) const {
		if (this->id == id) {
			return true;
		}
		return false;
	}
	virtual ~Pojazd() {};
	Pojazd(int id,string marka,string model,int licznik,string kolor)
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

class Samochod : public Pojazd{
protected:
	virtual void print(ofstream& o) const
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor << "\n";
	}
public:
	virtual bool szukaj_id(const vector<Pojazd*>& bazaPojazdow, int id) const {
		cout << "Szukam id samochodu" << endl;
		if (Pojazd::szukaj_id(bazaPojazdow,id)) {
			return true;
		}
		return false;

	}
	virtual ~Samochod() {};
	Samochod(int id, std::string marka, string model, int licznik,  string kolor)
		:Pojazd(id, marka, model, licznik, kolor) {
	//	cout << "Konstruktor dla samochodu" << endl;
	}
	
};

class Bus : public Pojazd
{
	
protected:
	double ladownosc;
	virtual void print(ofstream& o) const
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor <<", ladownosc: "<<this->ladownosc<< "\n";
	}
public:

	virtual bool szukaj_id(const vector<Pojazd*>& bazaPojazdow,int id) const {
		cout << "Szukam id busa" << endl;
		if (Pojazd::szukaj_id(bazaPojazdow, id)) {
			return true;
		}
		return false;
	}
	virtual ~Bus() {};
	Bus(int id, string marka,  string model, int licznik, string kolor,double ladownosc)
		:Pojazd( id,marka, model,licznik,kolor ), ladownosc{ ladownosc }{
	}
	
};
class Osoba {
	friend std::ofstream& operator<<(std::ofstream& os, const Osoba& account);
protected:
	string PESEL;
	string imie;
	string nazwisko;
	string dataUrodzenia;
	
public:
	Osoba(string PESEL, string imie, string nazwisko, string dataUrodzenia) 
		: PESEL{ PESEL }, imie{ imie }, nazwisko{ nazwisko }, dataUrodzenia{dataUrodzenia}{
	//	cout << "Konstruktor dla osoby" << endl;
	}
	~Osoba() {
		//cout << "Destruktor dla osoby" << endl;
	}
	bool szukajPesel(string PESEL)
	{
		if (this->PESEL==PESEL) 
		{
			return true; 
		}
		return false;
	}
	string getPESEL() {
		return this->PESEL;
	}
	string getFullName() {
		return this->imie +" "+ this->nazwisko;
	}


};
//std::ofstream& operator<<(std::ofstream& os, const Pojazd& pojazd) {
//	os << "Pojazd nr: " << pojazd.id << ", marka: " << pojazd.marka << ", model: " << pojazd.model << ",  stan licznika: " << pojazd.licznik << ", kolor: " << pojazd.kolor << "\n";
//	return os;
//}
//
//std::ofstream& operator<<(std::ofstream& os, const Samochod& pojazd) {
//	os << "Pojazd nr: " << pojazd.id << ", marka: " << pojazd.marka << ", model: " << pojazd.model << ",  stan licznika: " << pojazd.licznik << ", kolor: " << pojazd.kolor << "\n";
//	return os;
//}
//
//std::ofstream& operator<<(std::ofstream& os, const Bus& pojazd) {
//	os << "Pojazd nr: " << pojazd.id << ", marka: " << pojazd.marka << ", model: " << pojazd.model << ",  stan licznika: " << pojazd.licznik << ", kolor: " << pojazd.kolor << ", ladownosc: " << pojazd.ladownosc << "\n";
//	return os;
//}
std::ofstream& operator<<(std::ofstream& os, const Osoba& osoba) {
	os << "PESEL: " << osoba.PESEL << ", imie: " << osoba.imie << ", nazwisko: " << osoba.nazwisko << ", data urodzenia: " << osoba.dataUrodzenia  << "\n";
	return os;
}
std::ofstream& operator<< (std::ofstream& o, const Pojazd& b)
{
	b.print(o); 
	return o;
}

class Relacja {
private:
	string PESEL;
	int id;
public:
	Relacja(string PESEL, int id) 
		: PESEL{ PESEL }, id{id} {
	}
	string szukajPeselDlaId(int id) {
		if (this->id == id) {
			return this->PESEL;
		}
		return "";
	}
	int szukajIdDlaPESELA(string PESEL) {
		if (this->PESEL == PESEL) {
			return this->id;
		}
		return 0;
	}

	bool jestRelacja(string PESEL, int id) {
		if ((this->PESEL == PESEL) && (this->id == id)) {
			return true;
		}
		return false;
	}
	
	
};

vector<Pojazd*>& samochodyOsobyZpodanymPESEL(string podanyPESEL, const vector<Pojazd*>& bazaPojazdow,const vector<Osoba>& bazaOsob,
											 const vector<Relacja>& bazaRelacji, vector<Pojazd*>& pojazdyWynikowy) {
	for (auto osoba : bazaOsob) {
		if (osoba.szukajPesel(podanyPESEL)) {
			for (auto relacja : bazaRelacji) {
				int tempId{ relacja.szukajIdDlaPESELA(podanyPESEL) };
				for (auto pojazd : bazaPojazdow) {
					if (pojazd->szukaj_id(bazaPojazdow, tempId)) {
						pojazdyWynikowy.push_back(pojazd);
					}
				}
			}
		}
	}
	return pojazdyWynikowy;
}
vector<Osoba>& osobyZpojazdemPodanejMarki(string podanaMarka, const vector<Pojazd*>& bazaPojazdow, const vector<Osoba>& bazaOsob,
	const vector<Relacja>& bazaRelacji, vector<Osoba>& osobyWynikowy) {
	for (auto pojazd : bazaPojazdow) {
		if (pojazd->getMarka() == podanaMarka) {
			for (auto relacja : bazaRelacji) {
				string temp{ relacja.szukajPeselDlaId(pojazd->getId()) };
				for (auto osoba : bazaOsob) {
					if (osoba.szukajPesel(temp)) {
						bool duplikat{ false };
						if (osobyWynikowy.size() == 0) {
							osobyWynikowy.push_back(osoba);
						}
						for (auto osobaWynikowa : osobyWynikowy) {
							if (osoba.getPESEL() == osobaWynikowa.getPESEL()) {
								duplikat = true;
							}
						}
						if(!duplikat)

						osobyWynikowy.push_back(osoba);
						
					}
				}
			}
		}
	}
	return osobyWynikowy;
}



int main() {
	//vector<I_Zapisywalne*> bazaOsob;
	vector<Pojazd*> bazaPojazdow;
	vector<Osoba> bazaOsob;
	vector<Relacja> bazaRelacji;
	vector<Pojazd*> pojazdyWynikowy;
	vector<Osoba> OsobyWynikowy;


	Pojazd* ptr = new Samochod(1, "BMW", "E46", 10000, "czerwony");
	Pojazd* ptr2 = new Samochod(2, "Volvo", "E66", 20000, "niebieski");
	Pojazd* ptr3 = new Samochod(3, "BMW", "E96", 30000, "zielony");
	Pojazd* ptr4 = new Bus(4, "BMW", "E46", 43000, "czerwony", 3000.0);

	Osoba osoba1("98072001850", "Wiktor", "Wadas", "20.07.1998");
	Osoba osoba2("88072001851", "Janusz", "Kowalski", "14.04.1990");
	Osoba osoba3("98072001854", "Przemek", "Dzban", "05.07.1998");
	Osoba osoba4("68072001859", "Krzysztof", "Brzysztof", "20.07.1994");

	Relacja relacja1("98072001850", 1);
	Relacja relacja2("88072001851", 1);
	Relacja relacja3("98072001850", 2);
	Relacja relacja4("98072001854", 1);
	Relacja relacja5("68072001859", 4);
	Relacja relacja6("68072001859", 3);

	bazaOsob.push_back(osoba1);
	bazaOsob.push_back(osoba2);
	bazaOsob.push_back(osoba3);
	bazaOsob.push_back(osoba4);

	bazaPojazdow.push_back(ptr);
	bazaPojazdow.push_back(ptr2);
	bazaPojazdow.push_back(ptr3);
	bazaPojazdow.push_back(ptr4);

	bazaRelacji.push_back(relacja1);
	bazaRelacji.push_back(relacja2);
	bazaRelacji.push_back(relacja3);
	bazaRelacji.push_back(relacja4);
	bazaRelacji.push_back(relacja5);
	bazaRelacji.push_back(relacja6);

	string podanyPESEL = "68072001859";
	string podanaMarka = "BMW";

	samochodyOsobyZpodanymPESEL(podanyPESEL, bazaPojazdow, bazaOsob, bazaRelacji, pojazdyWynikowy);
	osobyZpojazdemPodanejMarki(podanaMarka, bazaPojazdow, bazaOsob, bazaRelacji, OsobyWynikowy);


	for (auto pojazd : pojazdyWynikowy) {
		cout << pojazd->getId() << endl;
	}
	for (auto osoba : OsobyWynikowy) {
		cout << osoba.getFullName() << endl;
	}

	ofstream myfile;
	//string plik = podanyPESEL+".txt";
	myfile.open("68072001859.txt");
	for (auto pojazd : pojazdyWynikowy) {
		myfile << *pojazd;
	}
		myfile.close();

	ofstream myfile2;
	//string plik = podanyPESEL+".txt";
	myfile.open("BMW.txt");
	for (auto osoba : OsobyWynikowy) {
		myfile << osoba;
	}
		myfile.close();
		return 0;
	
	
	
	//vector<Relacja> bazaRelacji;
}