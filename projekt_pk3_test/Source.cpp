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
#define ll long long 
using namespace std;

// Template class to create MojWektor of 
// different data_type 
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
		delete[] arr;
	}
};

// Template class to return the size of 
// MojWektor of different data_type 
template <typename TypDanych>
MojWektor<TypDanych>::MojWektor(int n)
	: dlugosc(n), arr(new TypDanych[n]), iloscObiektow(0)
{
}

// Template class to insert the element 
// in MojWektor 
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


// Template class to return the size of 
// MojWektor 
template <typename TypDanych>
int MojWektor<TypDanych>::size() const
{
	return iloscObiektow;
}

// Template class to return begin iterator 
template <typename TypDanych>
typename MojWektor<TypDanych>::iterator
MojWektor<TypDanych>::begin() const
{
	return iterator(arr);
}

// Template class to return end iterator 
template <typename TypDanych>
typename MojWektor<TypDanych>::iterator
MojWektor<TypDanych>::end() const
{
	return iterator(arr + iloscObiektow);
}

// Template class to display element in 
// MojWektor 
template <typename V>
void display_vector(V& v)
{
	// Declare iterator 
	typename V::iterator ptr;
	for (ptr = v.begin(); ptr != v.end(); ptr++) {
		cout << *ptr << ' ';
	}
	cout << '\n';
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
protected:
	virtual void print(ofstream& o) const 
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor << "\n";
	}
	virtual void read(ifstream& o)
	{
		o >> id >> marka >> model >> licznik >> kolor;
	}
public:
	virtual bool szukaj_id( int id) const override{
		cout << "Szukam id samochodu" << endl;
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
	virtual void print(ofstream& o) const
	{
		o << "Pojazd nr: " << this->id << ", marka: " << this->marka << ", model: " << this->model <<
			",  stan licznika: " << this->licznik << ", kolor: " << this->kolor <<", ladownosc: "<<this->ladownosc<< "\n";
	}
	virtual void read(ifstream& o)
	{
		o >> id >> marka >> model >> licznik >> kolor >> ladownosc;
	}
public:

	virtual bool szukaj_id(int id) const {
		cout << "Szukam id busa" << endl;
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
		//if (PESEL)
			delete[] PESEL;
		//if (imie)
			delete[] imie;
		//if (nazwisko)
			delete[] nazwisko;
		//if (dataUrodzenia)
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
std::ifstream& operator>>(std::ifstream& os, Osoba& osoba) {
	os >> osoba.PESEL >> osoba.imie >> osoba.nazwisko >> osoba.dataUrodzenia;
	return os;
}
std::ofstream& operator<< (std::ofstream& o, const Pojazd& b)
{
	b.print(o); 
	return o;
}
//std::ifstream& operator>> (std::ifstream& o,Pojazd& b)
//{
//	b.read(o);
//	return o;
//}



MojWektor<Pojazd*>& samochodyOsobyZpodanymPESEL(char* podanyPESEL, const MojWektor<Pojazd*>& bazaPojazdow,const MojWektor<Osoba> &bazaOsob,
											 const MojWektor<Relacja>& bazaRelacji, MojWektor<Pojazd*>& pojazdyWynikowy) {
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
	//delete[] temp;
	return pojazdyWynikowy;
}
MojWektor<Osoba>& osobyZpojazdemPodanejMarki(string podanaMarka, const MojWektor<Pojazd*>& bazaPojazdow, const MojWektor<Osoba>& bazaOsob,
	const MojWektor<Relacja>& bazaRelacji, MojWektor<Osoba>& osobyWynikowy) {
	for (auto pojazd : bazaPojazdow) {
		if (pojazd->getMarka() == podanaMarka) {
			for (auto relacja : bazaRelacji) {
				char* temp = new char[12];
				strcpy(temp, relacja.szukajPESELDlaId(pojazd->getId()).c_str());
				for (auto osoba : bazaOsob) {
					if (osoba.szukajPesel(temp)) {
						bool duplikat{ false };
						if (osobyWynikowy.size() == 0) {

							osobyWynikowy.push_back(osoba);
						}
						else {
							for (auto osobaWynikowa : osobyWynikowy) {
								if (osoba.getPESEL() == osobaWynikowa.getPESEL()) {
									duplikat = true;
								}
							}
							if (!duplikat) {

								osobyWynikowy.push_back(osoba);
							}
						}
					}
				}
				delete[] temp;
			}
		
		}
	}
	
	return osobyWynikowy;
}



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	
	
	MojWektor<Relacja> bazaRelacji;
	MojWektor<Pojazd*> pojazdyWynikowy;
	MojWektor<Osoba> OsobyWynikowy;


	//Pojazd* ptr = new Samochod(1, "BMW", "E46", 10000, "czerwony");
	//Pojazd* ptr2 = new Samochod(2, "Volvo", "E66", 20000, "niebieski");
	//Pojazd* ptr3 = new Samochod(3, "BMW", "E96", 30000, "zielony");
	//Pojazd* ptr4 = new Bus(4, "BMW", "E46", 43000, "czerwony", 3000.0);

	//char* tempPESEL1 = new char[12]{ "98072001850" };
	//char* tempPESEL2 = new char[12]{ "88072001851" };
	//char* tempPESEL3 = new char[12]{ "98072001854" };
	//char* tempPESEL4 = new char[12]{ "68072001859" };

	//char* tempImie1 = new char[7]{ "Wiktor" };
	//char* tempImie2 = new char[7]{ "Janusz" };
	//char* tempImie3 = new char[8]{ "Przemek" };
	//char* tempImie4 = new char[10]{ "Krzysztof" };

	//char* tempNazwisko1 = new char[6]{ "Wadas" };
	//char* tempNazwisko2 = new char[9]{ "Kowalski" };
	//char* tempNazwisko3 = new char[6]{ "Dzban" };
	//char* tempNazwisko4 = new char[10]{ "Brzysztof" };

	//char* tempDataUrodzenia1 = new char[11]{ "20.07.1998" };
	//char* tempDataUrodzenia2 = new char[11]{ "14.04.1990" };
	//char* tempDataUrodzenia3 = new char[11]{ "05.07.1998" };
	//char* tempDataUrodzenia4 = new char[11]{ "20.07.1994" };

	


	//Osoba osoba1(tempPESEL1,tempImie1,tempNazwisko1,tempDataUrodzenia1);
	//Osoba osoba2(tempPESEL2, tempImie2, tempNazwisko2, tempDataUrodzenia2);
	//Osoba osoba3(tempPESEL3, tempImie3, tempNazwisko3, tempDataUrodzenia3);
	//Osoba osoba4(tempPESEL4, tempImie4, tempNazwisko4, tempDataUrodzenia4);

	//Osoba* osoba1 = new Osoba(tempPESEL1, tempImie1, tempNazwisko1, tempDataUrodzenia1);
	//Osoba* osoba2 = new Osoba(tempPESEL2, tempImie2, tempNazwisko2, tempDataUrodzenia2);
	//Osoba* osoba3 = new Osoba(tempPESEL3, tempImie3, tempNazwisko3, tempDataUrodzenia3);
	//Osoba* osoba4 = new Osoba(tempPESEL4, tempImie4, tempNazwisko4, tempDataUrodzenia4);

	//Osoba osoba1(tempPESEL1, tempImie1, tempNazwisko1, tempDataUrodzenia1);
	//Osoba osoba2(tempPESEL2, tempImie2, tempNazwisko2, tempDataUrodzenia2);
	//Osoba osoba3(tempPESEL3, tempImie3, tempNazwisko3, tempDataUrodzenia3);
	//Osoba osoba4(tempPESEL4, tempImie4, tempNazwisko4, tempDataUrodzenia4);

	
	//osoba1->~Osoba();
	//delete osoba1;
	//osoba2->~Osoba();
	//osoba3->~Osoba();
	//osoba4->~Osoba();

	/*delete osoba1;
	delete osoba2;
	delete osoba3;
	delete osoba4;*/

	///*Osoba osoba2("88072001851", "Janusz", "Kowalski", "14.04.1990");
	//* 
	//Osoba osoba3("98072001854", "Przemek", "Dzban", "05.07.1998");
	//Osoba osoba4("68072001859", "Krzysztof", "Brzysztof", "20.07.1994");*/

	Relacja relacja1("98072001850", 1);
	Relacja relacja2("88072001851", 1);
	Relacja relacja3("98072001850", 2);
	Relacja relacja4("98072001854", 1);
	Relacja relacja5("68072001859", 4);
	Relacja relacja6("68072001859", 3);

	//bazaOsob.push_back(osoba1);
	//bazaOsob.push_back(osoba2);
	//bazaOsob.push_back(osoba3);
	//bazaOsob.push_back(osoba4);



	//bazaPojazdow.push_back(ptr);
	//bazaPojazdow.push_back(ptr2);
	//bazaPojazdow.push_back(ptr3);
	//bazaPojazdow.push_back(ptr4);


	bazaRelacji.push_back(relacja1);
	bazaRelacji.push_back(relacja2);
	bazaRelacji.push_back(relacja3);
	bazaRelacji.push_back(relacja4);
	bazaRelacji.push_back(relacja5);
	bazaRelacji.push_back(relacja6);

	char* podanyPESEL = new char[] {"68072001859"};
	string podanaMarka = "Volvo";


	MojWektor<Osoba> bazaOsob;


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

	//delete &bazaOsob;

	//bazaOsob = wczytajBazeOsob(bazaOsob);
	for (auto osoba : bazaOsob) {
		cout << osoba.getPESEL() << " " << osoba.getImie() << " " << osoba.getNazwisko() << " " << osoba.getData() << endl;
	}
	
	

	ifstream bazaPojazdowPlik;
	bazaPojazdowPlik.open("bazaPojazdowPlik.txt");
	MojWektor<Pojazd*> bazaPojazdow;

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
			//bus->~Pojazd();
			//delete bus;
		}
	}
	bazaPojazdowPlik.close();
	for (auto pojazd : bazaPojazdow) {
		cout << pojazd->getId()<<" " <<pojazd->getMarka() << endl;
	}

	samochodyOsobyZpodanymPESEL(podanyPESEL, bazaPojazdow, bazaOsob, bazaRelacji, pojazdyWynikowy);
	
	osobyZpojazdemPodanejMarki(podanaMarka, bazaPojazdow, bazaOsob, bazaRelacji, OsobyWynikowy);
	for (auto osoba : OsobyWynikowy) {
		cout << osoba.getPESEL() << " " << osoba.getImie() << " " << osoba.getNazwisko() << " " << osoba.getData() << endl;
	}
	//osobyZpojazdemPodanejMarki(podanaMarka, bazaPojazdow, bazaOsob, bazaRelacji, OsobyWynikowy);
	cout << "pojazdy wynikowe" << endl;
	for (auto pojazd : pojazdyWynikowy) {
		cout << pojazd->getId() << " " << pojazd->getMarka() << endl;
	}

	//for (auto pojazd : pojazdyWynikowy) {
	//	cout << pojazd->getId() << endl;
	//}
	/*for (auto osoba : OsobyWynikowy) {
		cout << osoba.getFullName() << endl;
	}*/

	ofstream myfile;
	///string plik = podanyPESEL+".txt";
	myfile.open("68072001859.txt");
	for (auto pojazd : pojazdyWynikowy) {
		myfile << *pojazd;
	}
		myfile.close();

	ofstream myfile2;
	////string plik = podanyPESEL+".txt";
	myfile.open("BMW.txt");
	for (auto osoba : OsobyWynikowy) {
		myfile << osoba;
	}
		myfile.close();

	//for (auto osoba : OsobyWynikowy) {
	//		osoba.~Osoba();
	//}
	//for (auto osoba : bazaOsob) {
	//	osoba.~Osoba();
	//}
	for (auto pojazd : bazaPojazdow) {
		pojazd->~Pojazd();
	}
	for (auto pojazd : pojazdyWynikowy) {
		pojazd->~Pojazd();
	}
	//delete bazaPojazdow;

	/*delete[] tempDataUrodzenia1;
	delete[] tempDataUrodzenia2;
	delete[] tempDataUrodzenia3;
	delete[] tempDataUrodzenia4;

	delete[] tempPESEL1;
	delete[] tempPESEL2;
	delete[] tempPESEL3;
	delete[] tempPESEL4;

	delete[] tempImie1;
	delete[] tempImie2;
	delete[] tempImie3;
	delete[] tempImie4;

	delete[] tempNazwisko1;
	delete[] tempNazwisko2;
	delete[] tempNazwisko3;
	delete[] tempNazwisko4;*/

	delete[] podanyPESEL;
	

	//ptr->~Pojazd();
	//ptr2->~Pojazd();
	//ptr3->~Pojazd();
	//ptr4->~Pojazd();

	//delete[] ptr;
	//delete[] ptr2;
	//delete[] ptr3;
	//delete[] ptr4;

		
		return 0;
	
	
	
	//MojWektor<Relacja> bazaRelacji;
}