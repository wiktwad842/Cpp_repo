#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

#define MAX_N 256
int MLI;
int N;
int Liczba_iteracji = 0;
int guard = 0;
double Mac_A[MAX_N][MAX_N], Wek_B[MAX_N];
double Mac_Alfa[MAX_N][MAX_N], Wek_Beta[MAX_N];
double Wek_Poprzedni[MAX_N], Wek_Aktualny[MAX_N];
double E;
double n1, n2, n3;

using namespace std;
void funkcja_czytajaca(string dane)
{
	//funkcja czyta macierz A i wektor B z pliku oraz rozmiar N macierzy A i wektorów B
	//i X,
	//dok³adnoœæ epsilon i maksymaln¹ liczbê iteracji (MLI) z klawiatury.
	//pobieranie danych wejsciowych od uzytkownika
	
	fstream plik;
	cout << "Podaj rozmiar N macierzy A i wektora B." << endl;
	cout << "Rozmiar nie powinien byc wiekszy niz " << MAX_N - 1 << endl;
	cout << "N = ";
	cin >> N;
	system("cls");
	cout << "Podaj dokladnosc Epsilon" << endl;
	cout << "Epsilon = ";
	cin >> E;
	system("cls");
	cout << "Podaj maksymalna liczbe iteracji" << endl;
	cout << "MLI = ";
	cin >> MLI;
	system("cls");
	//otworzenie pliku z danymi
	plik.open(dane, fstream::in | fstream::out | fstream::app);
	for (int i = 1; i <= N; i++) //wczytywanie z pliku Mac_A
	{
		for (int j = 1; j <= N; j++)
			plik >> Mac_A[i][j];
		plik.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	for (int i = 1; i <= N; i++) //wczytywanie z pliku Wek_B
	{
		plik >> Wek_B[i];
		plik.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//zamkniecie pliku z danymi
	plik.close();
}
void funkcja_tworzaca(void)
{
	//funkcja tworzy macierz alfa i wektor beta oraz sprawdza warunek utworzenia tych
	//elementów
		//przez dokonywanie kontroli dzielenia przez 0
		for (int i = 1; i <= N; i++) //utworzenie macierzy alfa
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					Mac_Alfa[i][j] = 0;
				else
				{
					if (Mac_A[i][i] != 0) //kontrola dzielenia przez zero
						Mac_Alfa[i][j] = -(Mac_A[i][j] / Mac_A[i][i]);
					else
					{
						cout << "Wykryto dzielenie przez 0 !" << endl;
						cout << "Przerwanie wykonywania obliczen" << endl;
						guard = 1;
						break;
					}
				}
			}
	for (int i = 1; i <= N; i++) //utworzenie wektora beta
		Wek_Beta[i] = Wek_B[i] / Mac_A[i][i];
}
void funkcja_wykonujaca(void)
{
	//funkcja wykonuje iteracje i testuje warunek stopu obliczeñ iteracyjnych
	for (int i = 0; i <= N; i++) //zerowanie wektora aktualnego i wektora poprzedniego
		Wek_Aktualny[i] = 0, Wek_Poprzedni[i] = 0;
	for (int i = 0; i <= N; i++) //zapis wektora beta do wektora aktualnego
		Wek_Aktualny[i] = Wek_Beta[i];
	do
	{
		Liczba_iteracji++;
		for (int i = 0; i <= N; i++) //zapis wektora aktualnego do wektora
			//poprzedniego
			Wek_Poprzedni[i] = Wek_Aktualny[i];
		for (int i = 0; i <= N; i++) //zerowanie wektora aktualnego
			Wek_Aktualny[i] = 0;
		for (int i = 1; i <= N; i++) //obliczanie nowego wektora aktualnego
		{
			for (int j = 1; j <= i - 1; j++)
				Wek_Aktualny[i] += Mac_Alfa[i][j] * Wek_Aktualny[j];
			for (int j = i + 1; j <= N; j++)
				Wek_Aktualny[i] += Mac_Alfa[i][j] * Wek_Poprzedni[j];
			Wek_Aktualny[i] += Wek_Beta[i];
		}
		double tmp = 0.0;
		for (int i = 1; i <= N; i++) //sprawdzanie stopu obliczeñ iteracyjnych
			if (tmp < abs(Wek_Aktualny[i] - Wek_Poprzedni[i]))
				tmp = abs(Wek_Aktualny[i] - Wek_Poprzedni[i]);
		if (tmp <= E)
			break;
	} while (Liczba_iteracji < MLI);
}
void funkcja_warunki_zbieznosci(void)
{
	//funkcja sprawdzaj¹ca warunki zbie¿noœci na podstawie
	//obliczenia normy pierwszej, drugiej i trzeciej macierzy alfa
	double tmp = 0;
	n1 = 0;
	for (int i = 1; i <= N; i++) //Obliczanie pierwszej normy macierzy alfa
	{
		for (int j = 1; j <= N; j++)
			tmp += abs(Mac_Alfa[i][j]);
		if (tmp > n1)
			n1 = tmp;
		tmp = 0;
	}
	n2 = 0;
	for (int j = 1; j <= N; j++) //Obliczanie drugiej normy macierzy alfa
	{
		for (int i = 1; i <= N; i++)
			tmp += abs(Mac_Alfa[i][j]);
		if (tmp > n2)
			n2 = tmp;
		tmp = 0;
	}
	n3 = 0;
	for (int i = 1; i <= N; i++) //Obliczanie trzeciej normy macierzy alfa
		for (int j = 1; j <= N; j++)
			n3 += Mac_Alfa[i][j] * Mac_Alfa[i][j];
	n3 = sqrt(n3);
}
void funkcja_generujaca(string dane)
{
	//funkcja generuj¹ca raport do pliku
	//utworzenie pliku raportu
	fstream plik;
	plik.open("wyniki_" + dane, fstream::in | fstream::out | fstream::app);
	plik.precision(10);
	plik << "RAPORT " << dane << " : " << endl << endl;
	plik << "####################" << endl;
	plik << "# DANE WEJSCIOWE : #" << endl;
	plik << "####################" << endl << endl;
	plik << "Macierz A :" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			plik << Mac_A[i][j] << "\t";
		plik << endl;
	}
	plik << endl << "Wektor B :" << endl;
	for (int i = 1; i <= N; i++)
		plik << Wek_B[i] << endl;
	plik << endl << "Dokladnosc Epsilon : " << E << endl;
	plik << "Maksymalna liczba iteracji : " << MLI << endl << endl << endl;
	if (guard == 1) //wyjatek podczas generowania raportu w przypadku wykrycia dzielenia
		//przez zero
	{
		plik << "Nie jest mozliwe obliczenie rozwiazania dla podanych danych wejsciowych metoda Seidela" << endl;
	
	plik.close();
	cout << "Plik wyniki_" + dane + " zostal wygenerowany." << endl;
	cout << endl;
	system("pause");
	exit(1);
	}
	plik << "####################" << endl;
	plik << "# DANE POSREDNIE : #" << endl;
	plik << "####################" << endl << endl;
	plik << "Macierz Alfa :" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			plik << Mac_Alfa[i][j] << "\t";
		plik << endl;
	}
	plik << endl << "Wektor Beta :" << endl;
	for (int i = 1; i <= N; i++)
		plik << Wek_Beta[i] << endl;
	plik << " " << endl << endl;
	plik << "#####################" << endl;
	plik << "# WYNIKI OBLICZEN : #" << endl;
	plik << "#####################" << endl << endl;
	plik << "Wektor przedostatnio wykonanej iteracji : " << endl;
	for (int i = 1; i <= N; i++)
		plik << Wek_Poprzedni[i] << endl;
	plik << endl << "Wektor ostatnio wykonanej iteracji : " << endl;
	for (int i = 1; i <= N; i++)
		plik << Wek_Aktualny[i] << endl;
	plik << " " << endl;
	plik << "Liczba wykonanych iteracji: " << Liczba_iteracji << endl << endl << endl;
	plik << "#############" << endl;
	plik << "# ANALIZA : #" << endl;
	plik << "#############" << endl << endl;
	plik << "Blad bezwzgledny rozwiazania : " << endl;
	plik << fixed;
	for (int i = 1; i <= N; i++)
		plik << abs(1 - Wek_Aktualny[i]) << endl;
	plik.unsetf(ios_base::floatfield);
	plik << endl << "Warunki zbieznosci:" << endl << endl;
	plik << "Norma I Macierzy Alfa: " << n1 << endl;
	plik << "Norma II Macierzy Alfa: " << n2 << endl;
	plik << "Norma III Macierzy Alfa: " << n3 << endl;
	if ((n1 < 1) || (n2 < 1) || (n3 < 1))
		plik << endl << "Warunki zbieznosci zostaly spelnione." << endl;
	else
		plik << endl << "Warunki zbieznosci nie zostaly spelnione." << endl;
	plik.close();
	cout << "Plik wyniki_" + dane + " zostal wygenerowany." << endl;
}
int main()
{
	string dane;
	cout << "Program rozwiazujacy uklad rownan AX=B metoda Seidela." << endl << endl;
	system("pause");
	system("cls");

	cout << "Podaj nazwe pliku zawierajacego macierz A i wektor B." << endl;
	cout << "Nazwa pliku : ";
	cin >> dane;
	system("cls");
	
	funkcja_czytajaca(dane);
	funkcja_tworzaca();
	funkcja_wykonujaca();
	funkcja_warunki_zbieznosci();
	funkcja_generujaca(dane);
	cout << endl;
	system("pause");
	return 0;
}