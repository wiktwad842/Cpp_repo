#include "Osoba.h"

std::ifstream& operator>>(std::ifstream& is, Osoba& osoba) {
	is >> osoba.PESEL >> osoba.imie >> osoba.nazwisko >> osoba.dataUrodzenia;
	return is;
}


std::ofstream& operator<<(std::ofstream& os, const Osoba& osoba) {
	os << "PESEL: " << osoba.PESEL << ", imie: " << osoba.imie << ", nazwisko: " << osoba.nazwisko << ", data urodzenia: " << osoba.dataUrodzenia << "\n";
	return os;
}