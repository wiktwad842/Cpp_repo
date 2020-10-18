#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
	cout << boolalpha << endl;
	Mystring apple{ "Apple" };
	Mystring apple2 = -apple;
	
	apple2.display();
	apple.display();

	Mystring obj1{ "Banana" };
	bool temp = apple == apple;
	cout << temp << endl;

	//Mystring obj2 = obj1 + apple;
	//obj2.display();

	//obj1 += apple; 
	//obj1.display();

	
	//Mystring obj3 = apple * 3;
	//obj3.display();

	apple *= 4;
	apple.display();


	return 0;
}