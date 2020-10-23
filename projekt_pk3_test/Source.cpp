#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;

template <typename TypDanych>
class MojWektor {
private:
	TypDanych* arr;
	int iloscObiektow;
	int dlugosc;
	
public:
	explicit MojWektor(int = 100);
	int push_back(TypDanych);
	int size() const;
	class iterator;


	class iterator {
	private:

		TypDanych* ptr;

	public:
		explicit iterator()
			: ptr(nullptr)
		{
		}
		explicit iterator(TypDanych* p)
			: ptr(p)
		{
		}
		bool operator==(const iterator& rhs) const
		{
			return ptr == rhs.ptr;
		}
		bool operator!=(const iterator& rhs) const
		{
			return !(*this == rhs);
		}
		TypDanych operator*() const
		{
			return *ptr;
		}
		iterator& operator++()
		{
			++ptr;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp(*this);
			++* this;
			return temp;
		}
	};

	iterator begin() const;
	iterator end() const;

	~MojWektor() {
		if(arr)
		delete[] arr;
	}
};

template <typename TypDanych>
MojWektor<TypDanych>::MojWektor(int n)
	: dlugosc(n), arr(new TypDanych[n]), iloscObiektow(0)
{
}

template <typename TypDanych>
int MojWektor<TypDanych>::push_back(TypDanych data)
{
	if (dlugosc == iloscObiektow) {
		TypDanych* old = arr;
		arr = new TypDanych[dlugosc = dlugosc * 2];
		copy(old, old + iloscObiektow, arr);
		delete[] old;
	}
	arr[iloscObiektow++] = data;
	return iloscObiektow;
}

template <typename TypDanych>
int MojWektor<TypDanych>::size() const
{
	return iloscObiektow;
}

template <typename TypDanych>
typename MojWektor<TypDanych>::iterator
MojWektor<TypDanych>::begin() const
{
	return iterator(arr);
}

template <typename TypDanych>
typename MojWektor<TypDanych>::iterator
MojWektor<TypDanych>::end() const
{
	return iterator(arr + iloscObiektow);
}

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
	virtual bool szukaj_id( int id) const override{
		//cout << "Szukam id samochodu" << endl;
		if (Pojazd::szukaj_id(id)) {
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
		:Pojazd(id, marka, model, licznik, kolor),ladownosc {ladownosc}{
	
	}
	
};

class Osoba {
	friend std::ofstream& operator<<(std::ofstream& os, const Osoba& osoba);
	friend std::ifstream& operator>>(std::ifstream& os, Osoba& osoba);
protected:
	char* PESEL;
	char* imie;
	char* nazwisko;
	char* dataUrodzenia;
	
public:
	Osoba()
		:PESEL{ nullptr }, imie{ nullptr }, nazwisko{ nullptr }, dataUrodzenia{nullptr} {
		if (PESEL == nullptr) 
			PESEL = new char[1]{ '\0' };
		if (imie == nullptr)
			imie = new char[1]{ '\0' };
		if (nazwisko == nullptr)
			nazwisko = new char[1]{ '\0' };
		if (dataUrodzenia == nullptr)
			dataUrodzenia = new char[1]{ '\0' };
		//cout << "Konstruktor bezargumentowy osoby" << endl;
	}
	Osoba(char* PESEL, char* imie, char* nazwisko, char* dataUrodzenia) 
		: PESEL{ new char[strlen(PESEL)+1] }, imie{ new char[strlen(imie)+1] }, 
		nazwisko{ new char[strlen(nazwisko) + 1] }, dataUrodzenia{ new char[strlen(dataUrodzenia) + 1] }{
		strcpy(this->PESEL, PESEL);
		strcpy(this->imie, imie);
		strcpy(this->nazwisko, nazwisko);
		strcpy(this->dataUrodzenia, dataUrodzenia);
		//cout << "Konstruktor wieloargumentowy osoby" << endl;
	}
	~Osoba() {
		if (PESEL)
			delete[] PESEL;
		if (imie)
			delete[] imie;
		if (nazwisko)
			delete[] nazwisko;
		if (dataUrodzenia)
			delete[] dataUrodzenia;
			//cout << "Destruktor osoby" << endl;
	}
Osoba(const Osoba& source) 
		: PESEL{ new char[strlen(source.PESEL)+1] }, imie{ new char[strlen(source.imie) + 1] }, nazwisko{ new char[strlen(source.nazwisko) + 1] },
		  dataUrodzenia{ new char[strlen(source.dataUrodzenia) + 1] } {
		strcpy(PESEL, source.PESEL);
		strcpy(imie, source.imie);
		strcpy(nazwisko, source.nazwisko);
		strcpy(dataUrodzenia, source.dataUrodzenia);
		//cout<<"Konstruktor kopiujacy osoby"<<endl;
}
	Osoba(Osoba&& source)  noexcept
		:PESEL{ source.PESEL }, imie{ source.imie }, nazwisko{ source.nazwisko }, dataUrodzenia{ source.dataUrodzenia } {
		source.PESEL = nullptr;
		source.imie = nullptr;
		source.nazwisko = nullptr;
		source.dataUrodzenia = nullptr;
		//cout << "Konstruktor przenoszacy osoby" << endl;
	}
	Osoba& operator=(const Osoba& rhs) {
		if (this == &rhs)
			return *this;
		delete[] this->PESEL;
		delete[] this->imie;
		delete[] this->nazwisko;
		delete[] this->dataUrodzenia;
		this->PESEL = new char[strlen(rhs.PESEL) + 1];
		this->imie = new char[strlen(rhs.imie) + 1];
		this->nazwisko = new char[strlen(rhs.nazwisko) + 1];
		this->dataUrodzenia = new char[strlen(rhs.dataUrodzenia) + 1];
		strcpy(PESEL, rhs.PESEL);
		strcpy(imie, rhs.imie);
		strcpy(nazwisko, rhs.nazwisko);
		strcpy(dataUrodzenia, rhs.dataUrodzenia);
		return*this;
		//cout << "Operator kopiujacy" << endl;

	}
	bool szukajPesel(const char* PESEL)const 
	{
		if (strcmp(this->PESEL,PESEL)==0) 
		{
			return true; 
		}
		return false;
	}
	const char* getPESEL() const{
		return this->PESEL;
	}
	const char* getImie()const{
		return this->imie;
	}
	const char* getNazwisko()const {
		return this->nazwisko;
	}
	const char* getData()const {
		return this->dataUrodzenia;
	}
	/*string getFullName() {
		return this->imie +" "+ this->nazwisko;
	}*/
	//Osoba& operator=(const Osoba& rhs);
	//Osoba& operator=(Osoba&& rhs);
	Osoba& setPESEL(char* str) {
		if (PESEL)
			delete[] PESEL;
		PESEL = new char[strlen(str) + 1];
		strcpy(PESEL, str);
	}
};

class Relacja {
	friend  std::ifstream& operator>>(std::ifstream& os, Relacja& relacja);
private:
	string PESEL;
	int id;
public:
	Relacja()
		:PESEL{ "" }, id{-1} {}
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
	~Relacja(){}


};

std::ofstream& operator<<(std::ofstream& os, const Osoba& osoba) {
	os << "PESEL: " << osoba.PESEL << ", imie: " << osoba.imie << ", nazwisko: " << osoba.nazwisko << ", data urodzenia: " << osoba.dataUrodzenia  << "\n";
	return os;
}

std::ifstream& operator>>(std::ifstream& is, Osoba& osoba) {
	is >> osoba.PESEL >> osoba.imie >> osoba.nazwisko >> osoba.dataUrodzenia;
	return is;
}

std::ofstream& operator<< (std::ofstream& o, const Pojazd& b)
{
	b.print(o); 
	return o;
}

std::ifstream& operator>>(std::ifstream& is, Relacja& relacja) {
	is >> relacja.PESEL >> relacja.id;
	return is;
}

MojWektor<Pojazd*>& samochodyOsobyZpodanymPESEL(string podanyPESEL_str, const MojWektor<Pojazd*>& bazaPojazdow,const MojWektor<Osoba> &bazaOsob,
											 const MojWektor<Relacja>& bazaRelacji, MojWektor<Pojazd*>& pojazdyWynikowy) {
	char* podanyPESEL = new char[podanyPESEL_str.length() + 1];
	strcpy(podanyPESEL, podanyPESEL_str.c_str());
	for (auto osoba : bazaOsob) {
		if (osoba.szukajPesel(podanyPESEL)) {
			for (auto relacja : bazaRelacji) {
				int tempId{ relacja.szukajIdDlaPESEL(podanyPESEL) };
				for (auto pojazd : bazaPojazdow) {
					if (pojazd->szukaj_id(tempId)) {

						pojazdyWynikowy.push_back(pojazd);
					}
				}
			}
		}
	}
	delete[] podanyPESEL;
	
	return pojazdyWynikowy;
}

MojWektor<Osoba>& osobyZpojazdemPodanejMarki(string podanaMarka, const MojWektor<Pojazd*>& bazaPojazdow, const MojWektor<Osoba>& bazaOsob,
	const MojWektor<Relacja>& bazaRelacji, MojWektor<Osoba>& osobyWynikowy) 
{
	for (auto pojazd : bazaPojazdow){
		if (pojazd->getMarka() == podanaMarka){
			for (auto relacja : bazaRelacji){
				char* temp = new char[12];
				strcpy(temp, relacja.szukajPESELDlaId(pojazd->getId()).c_str());
				for (auto osoba : bazaOsob){
					if (osoba.szukajPesel(temp)){
						bool duplikat{ false };
						if (osobyWynikowy.size() == 0){

							osobyWynikowy.push_back(osoba);
						}
						else{

							for (auto osobaWynikowa : osobyWynikowy){
								if (osoba.getPESEL() != osobaWynikowa.getPESEL())
									duplikat = true;
								
							}
							if (!duplikat)
								osobyWynikowy.push_back(osoba);
						}
					}	
				}delete[] temp;
			}
		}
	}
	return osobyWynikowy;
}

MojWektor<Osoba>& wczytajBazeOsob(MojWektor<Osoba>&bazaOsob) {
	MojWektor<Osoba> temp;
	ifstream bazaOsobPlik;
	bazaOsobPlik.open("bazaOsobPlik.txt");
	while (bazaOsobPlik) {
		string tempPESEL_str;
		string tempImie_str;
		string tempNazwisko_str;
		string tempData_str;

		bazaOsobPlik >> tempPESEL_str;
		bazaOsobPlik >> tempImie_str;
		bazaOsobPlik >> tempNazwisko_str;
		bazaOsobPlik >> tempData_str;

		char* tempPESEL = new char[tempPESEL_str.length() + 1];
		char* tempImie = new char[tempImie_str.length() + 1];
		char* tempNazwisko = new char[tempNazwisko_str.length() + 1];
		char* tempData = new char[tempData_str.length() + 1];

		strcpy(tempPESEL, tempPESEL_str.c_str());
		strcpy(tempImie, tempImie_str.c_str());
		strcpy(tempNazwisko, tempNazwisko_str.c_str());
		strcpy(tempData, tempData_str.c_str());

		Osoba tempOsoba{ tempPESEL,tempImie ,tempNazwisko,tempData };
		if (tempPESEL_str.length() != 0)
			bazaOsob.push_back(tempOsoba);
		/*bazaOsobPlik >> tempImie;
		bazaOsobPlik >> tempNazwisko;
		bazaOsobPlik >> tempData;*/
		/*tempPESEL.c_str();*/
		delete[]tempPESEL;
		delete[]tempImie;
		delete[]tempNazwisko;
		delete[]tempData;
		//delete &tempOsoba;

	}
	bazaOsobPlik.close();
	return bazaOsob;
}

MojWektor<Pojazd*>& wczytajBazePojazdow(MojWektor<Pojazd*>& bazaPojazdow) {
	ifstream bazaPojazdowPlik;
	bazaPojazdowPlik.open("bazaPojazdowPlik.txt");

	while (bazaPojazdowPlik) {
		string rodzaj;
		int id;
		string marka;
		string model;
		int licznik;
		string kolor;
		double ladownosc;
		bazaPojazdowPlik >> rodzaj;
		if (rodzaj == "samochod") {
			bazaPojazdowPlik >> id;
			bazaPojazdowPlik >> marka;
			bazaPojazdowPlik >> model;
			bazaPojazdowPlik >> licznik;
			bazaPojazdowPlik >> kolor;
			Pojazd* samochod = new Samochod{ id,marka,model,licznik,kolor };
			bazaPojazdow.push_back(samochod);
			//samochod->~Pojazd();
			//delete samochod;
		}
		if (rodzaj == "bus") {
			bazaPojazdowPlik >> id;
			bazaPojazdowPlik >> marka;
			bazaPojazdowPlik >> model;
			bazaPojazdowPlik >> licznik;
			bazaPojazdowPlik >> kolor;
			bazaPojazdowPlik >> ladownosc;
			Pojazd* bus = new Bus{ id, marka, model, licznik, kolor, ladownosc };
			bazaPojazdow.push_back(bus);
			//(*bus).~Pojazd();
			//delete bus;
		}

	}
	bazaPojazdowPlik.close();
	return bazaPojazdow;
}

MojWektor<Relacja>& wczytajBazeRelacji(MojWektor<Relacja>& bazaRelacji) {

	ifstream bazaRelacjiPlik;
	bazaRelacjiPlik.open("bazaRelacji.txt");

	while (bazaRelacjiPlik) {
		Relacja temp;
		bazaRelacjiPlik >> temp;
		bazaRelacji.push_back(temp);
	}
	bazaRelacjiPlik.close();
	return bazaRelacji;
}

void zapiszPojazdy(MojWektor<Pojazd*>&wektorPojazdow,string nazwaPliku) {
	nazwaPliku += ".txt";
	ofstream myfile;
	myfile.open(nazwaPliku);
	for (auto pojazd : wektorPojazdow) {
		myfile << *pojazd;
	}
	myfile.close();
}

void zapiszOsoby(MojWektor<Osoba>& wektorOsob, string nazwaPliku) {
	nazwaPliku += ".txt";
	ofstream myfile2;
	myfile2.open(nazwaPliku);
	for (auto osoba : wektorOsob) {
		myfile2 << osoba;
	}
	myfile2.close();
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MojWektor<Relacja> bazaRelacji;

	MojWektor<Osoba> bazaOsob;

	MojWektor<Pojazd*> bazaPojazdow;

	MojWektor<Pojazd*> pojazdyWynikowy;

	MojWektor<Osoba> OsobyWynikowy;

	wczytajBazeOsob(bazaOsob);

	wczytajBazePojazdow(bazaPojazdow);

	wczytajBazeRelacji(bazaRelacji);

	string marka = "BMW";

	string PESEL = "98072001850";

	zapiszPojazdy(samochodyOsobyZpodanymPESEL(PESEL, bazaPojazdow, bazaOsob, bazaRelacji, pojazdyWynikowy), PESEL);

	zapiszOsoby(osobyZpojazdemPodanejMarki(marka, bazaPojazdow, bazaOsob, bazaRelacji, OsobyWynikowy), marka);
	
	for (auto pojazd : bazaPojazdow) {
		delete [] pojazd;
	}
		return 0;
}