#include <iostream>
using namespace std;
int main() {
	//1
	/*
	int a, b, c;
	cin >> a;
	cin >> b;
	cout << "suma " << a + b << endl;
	cout << "roznica " << a - b << endl;
	cout << "iloczyn " << a * b << endl;
	c = a | b;
	cout << "suma bitowa " << c << endl;
	c = a & b;
	cout << "iloczyn bitowy " << c << endl; 
	c = a ^ b;
	cout << "roznica symetryczna " << c << endl;
	c = a <<= b;
	cout << "przesuniecie bitowe " << c << endl;
	
	cout << "dzielenie z reszta " << a % b << endl;
	*/
	//2
	/*
	double a1, a2, b1, b2, c1, c2, wx, wy, w, x, y;
	cout << "a1: " << endl;
	cin >> a1;
	cout << "a2: " << endl;
	cin >> a2;
	cout << "b1: " << endl;
	cin >> b1;
	cout << "b2: " << endl;
	cin >> b2;
	cout << "c1: " << endl;
	cin >> c1;
	cout << "c2: " << endl;
	cin >> c2;


	w = a1 * b2 - b1 * a2;
	wx = c1 * b2 - b1 * c2;
	wy = a1 * c2 - c1 * a2;

	if (w != 0) {
		cout << "x = " << wx / w << endl;
		cout << "y = " << wy / w << endl;

	}
	else
		if (wx == 0 && wy == 0)
		{
			cout << "Nieskonczenie wiele" << endl;
		}
		else
			cout << "Sprzeczny" << endl;
	*/
	//3
	/*
	double a;
	double b;
	double c;
	double d;

	cout << "A: " << endl;
	cin >> a;
	cout << "B: " << endl;
	cin >> b;
	cout << "C: " << endl;
	cin >> c;
	cout << "D: " << endl;
	cin >> d;
	
	d = b * b - 4 * a * c;
	if (a != 0)
	{


		if (d > 0)
		{
			cout << "x1=" << (-b + sqrt(d)) / 2 * a << endl;
			cout << "x1=" << (-b - sqrt(d)) / 2 * a << endl;

		}
		else if (d == 0) {
			cout << "x= " << -b / 2 * a << endl;
		}
		else
			cout << "Nie ma pierwiastków" << endl;

	}
	else
		cout << "Funkcja liniowa";
	*/



	///////////////////////////////////////4
	/*
	int day;
	int iterator=0;
	bool flaga;
	flaga = false;
	

	cin >> day;

	int n[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (!flaga) {
		if (day - n[iterator] > 0) 
		{
			day -= n[iterator];
			iterator++;
		}
		else
		{
			flaga = true;
			cout << "<" << day << ">" << "<" << iterator + 1 << ">";
		}
		
	}

	*/



////////////////////////////////////////////5
/*
int rok;
cout << "Podaj rok: ";
cin >> rok;
if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) {
	cout << "Rok jest przestepny.";
}
else {
	cout << "Rok nie jest przestepny";
}
cout << endl;
*/


int rok;
cin >> rok;
int licznik = 0;
for (int i = 1; i < rok; i++) {

	if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
		licznik++;
	}
	
}
cout << licznik;


	return 0;
}