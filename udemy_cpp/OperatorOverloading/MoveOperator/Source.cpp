#include <iostream>
#include "Mystring.h"



int main() {

	Mystring a{ "Hello" };
	a = Mystring{ "Hola" };
	a = "Bonjour";
	Mystring a2;
	a2 = -a;
	std::cout << std::endl;
	a.display();
	std::cout << std::endl;

	a2.display();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	Mystring larry{ "Larry" };
	Mystring moe{ "Moe" };
	Mystring stooges{ " is one of the three stooges" };
	Mystring result = larry +stooges+larry;

	result.display();

	//Mystring empty;           //no args constructor
	//Mystring larry("Larry");  //overloaded constructor
	//Mystring john("John");
	//Mystring stooge{ larry }; // copy constructor

	//Mystring test = larry + john;
	//test.display();
	//empty.display();
	//larry.display();
	//stooge.display();
	return 0;
}

