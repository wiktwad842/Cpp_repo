#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<string.h>
#include "Pojazd.h"
#include "Osoba.h"
#include "Samochod.h"
#include "Bus.h"
#include "Relacja.h"
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
	bazaOsobPlik.open("bazaOsob.txt");
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
	bazaPojazdowPlik.open("bazaPojazdow.txt");

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

	string PESEL = "68072001859";

	zapiszPojazdy(samochodyOsobyZpodanymPESEL(PESEL, bazaPojazdow, bazaOsob, bazaRelacji, pojazdyWynikowy), PESEL);

	zapiszOsoby(osobyZpojazdemPodanejMarki(marka, bazaPojazdow, bazaOsob, bazaRelacji, OsobyWynikowy), marka);
	
	for (auto pojazd : bazaPojazdow) {
		delete [] pojazd;
	}
		return 0;
}