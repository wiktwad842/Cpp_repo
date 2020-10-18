#include "Mystring.h"
#pragma warning (disable: 4996)
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
		//cout << "Contructor called for : " << str << endl;
	}

}
Mystring::Mystring(const Mystring& source)
	: str{ new char[strlen(source.str) + 1] } {
	cout << "Copy constructor caled for : " << str<<endl;
	strcpy(str, source.str);
}

Mystring::Mystring(Mystring&& source)
	: str(source.str) {
	source.str = nullptr;
	cout << "Move constructor used" << endl;
}

Mystring::~Mystring() {
	if (str == nullptr) {
		cout << "Calling destructor for Mystring : nullptr" << endl;
	}
	else {
		cout << "Calling destructor for: " << str << endl;
		delete[] str;
	}
}
//two string equal
bool Mystring::operator==(const Mystring& rhs)const {
	if (strcmp(this->str, rhs.str) == 0) {
		return true;
	}
	return false;
}
//two strings not equal
bool Mystring::operator!=(const Mystring & rhs) const{
	if (strcmp(this->str, rhs.str) != 0) {
		return true;
	}
	return false;

}
//first string is lexically less
bool Mystring::operator<(const Mystring& rhs)const {
	if (strcmp(this->str, rhs.str) < 0) {
		return true;
	}
	return false;

}
//first string is lexically greater
bool Mystring::operator>(const Mystring& rhs)const {
	if (strcmp(this->str, rhs.str) > 0) {
		return true;
	}
	return false;

}
//concatenation but while changing object instead creating new one
Mystring& Mystring::operator+=(const Mystring& rhs) {
	char* buff = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff, rhs.str);
	delete[] str;
	str = buff;
	buff = nullptr;
	return *this;
}

//concatenation
Mystring Mystring::operator+(const Mystring& rhs)const {
	char* buff = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(buff, str);
	strcat(buff, rhs.str);
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}
//multiplying changing object
Mystring& Mystring::operator*=(int n) {
	char* buff = new char[(n * strlen(str)) + 1];
	strcpy(buff, str);
	for (int i = 0; i < n - 1; i++) {
		strcat(buff, str);
	}
	delete[]str;
	str = buff;
	buff = nullptr;
	return*this;
}
//multiplying
Mystring Mystring::operator*(int n)const {
	char* buff = new char[(n * strlen(str)) +1];
	strcpy(buff, str);
	for (int i = 0; i < n-1; i++) {
		strcat(buff, str);
	}
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}
//return lower case
Mystring Mystring::operator-() const{
	char* buff = new char[strlen(str) + 1];
	strcpy(buff, str);
	for (int i = 0; i < strlen(str); i++) {
		buff[i] = tolower(str[i]);
	}
	Mystring temp{ buff };
	delete[]buff;
	return temp;
}

Mystring& Mystring::operator=(const Mystring& rhs) {
	cout << "Copy assignment" << endl;
	if (this == &rhs)
		return *this;
	delete[] this->str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
}

Mystring& Mystring::operator=(Mystring&& tempStr) {
	cout << "Move operator used" << endl;
	if (this == &tempStr) {
		return *this;
	}
	delete[]str;
	str = tempStr.str; //stealing pointer
	tempStr.str = nullptr;
	return*this;
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