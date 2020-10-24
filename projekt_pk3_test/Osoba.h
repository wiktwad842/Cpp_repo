#pragma once
#pragma warning(disable:4996)
#include <fstream>

using namespace std;
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
		:PESEL{ nullptr }, imie{ nullptr }, nazwisko{ nullptr }, dataUrodzenia{ nullptr } {
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
		: PESEL{ new char[strlen(PESEL) + 1] }, imie{ new char[strlen(imie) + 1] },
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
		: PESEL{ new char[strlen(source.PESEL) + 1] }, imie{ new char[strlen(source.imie) + 1] }, nazwisko{ new char[strlen(source.nazwisko) + 1] },
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
		if (strcmp(this->PESEL, PESEL) == 0)
		{
			return true;
		}
		return false;
	}
	const char* getPESEL() const {
		return this->PESEL;
	}
	const char* getImie()const {
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
