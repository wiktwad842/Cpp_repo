#include <iostream>
#include "Mystring.h"



int main() {

	Mystring a{ "Hello" };
	Mystring b;
	b = a;
	b = "This is a test";

	b.display();




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

