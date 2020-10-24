#include "Pojazd.h"
std::ofstream& operator<< (std::ofstream& o, const Pojazd& b)
{
	b.print(o);
	return o;
}