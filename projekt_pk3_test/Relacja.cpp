#include "Relacja.h"

std::ifstream& operator>>(std::ifstream& is, Relacja& relacja) {
	is >> relacja.PESEL >> relacja.id;
	return is;
}