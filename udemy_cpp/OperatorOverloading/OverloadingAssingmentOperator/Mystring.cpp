#include "Mystring.h"
#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)
using namespace std;
Mystring::Mystring()
	:str{ nullptr } {
	str = new char[1]{ '\0' };
}

Mystring::Mystring(const char* s)
	: str{ nullptr } {
	if (s == nullptr) {
		str = new char[1]{ '\0' };
		//*str = '\0';
	}
	else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}

}

Mystring::Mystring(const Mystring& source)
	: str{ new char[strlen(source.str) + 1] } {
	strcpy(str, source.str);
}
//Mystring& Mystring::operator+(const Mystring& strToAdd) {
//	if (strToAdd.str)
//		return *this;
//	char* temp = new char[strlen(str)+1];
//	strcpy(temp, str);
//	delete[]str;
//	str = new char[strlen(strToAdd.str) + strlen(temp) + 1];
//	strcpy(str, temp-1);
//	strcpy(str + *temp, strToAdd.str);
//	return *this;
//
//}
Mystring &Mystring::operator=(const Mystring& rhs) {
	cout << "Copy assignment" << endl;
	if (this == &rhs)
		return *this;
	delete[] this->str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
}



Mystring::~Mystring() {
	if (str)
		delete[] str;
}

void Mystring::display()const {
	cout << str << " : " << getLenght() << endl;
}

int Mystring::getLenght()const {
	return strlen(str);
}

const char* Mystring::getStr()const {
	return this->str;
}