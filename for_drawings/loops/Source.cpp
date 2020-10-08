#include <iostream>
using namespace std;

void wypelnij1(char tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j == 0 || i == 9 || i == 0 || j == 9 || i==j||i+j==9)
				tab[i][j] = 'X';
		}
	}
}

void wypelnij2(char tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (i >= j&&i+j<10) {
				tab[i][j] = 'X';
			}
		}
	}
}

void wypelnij3(char tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			tab[i][j] = 'X';
		}
	}
}

void wyswietl(char tab[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
}


int main() {
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "X";
		}
		cout << endl;
	}*/
	char tab[10][10] = {};

	//wypelnij1(tab);

	//wyswietl(tab);
	cout << endl;

	wypelnij2(tab);

	wyswietl(tab);
	cout << endl;


	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < j+1) {
				cout << "X";
			}

		
		cout << endl;
	}*/
	return 0;
}
	