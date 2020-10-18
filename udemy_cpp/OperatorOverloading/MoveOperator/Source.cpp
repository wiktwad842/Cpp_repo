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

