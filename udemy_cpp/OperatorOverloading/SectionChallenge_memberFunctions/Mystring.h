#pragma once
using namespace std;
#include <iostream>
class Mystring
{
	friend std::ostream &operator<<(std::ostream& os, const Mystring& rhs);
	friend std::istream &operator>>(std::istream& in, Mystring& rhs);

private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(const Mystring& source);
	Mystring(Mystring&& source);
	~Mystring();
	Mystring& operator=(const Mystring& rhs);  //copy assignment
	Mystring& operator=(Mystring&& rhs);       //move assignment
	Mystring operator-()const;                 //lower case
	bool operator==(const Mystring& rhs) const;//equality
	bool operator!=(const Mystring& rhs)const; //inequality
	bool operator<(const Mystring& rhs)const; //1st is less
	bool operator>(const Mystring& rhs)const; //1st i greater
	Mystring operator+(const Mystring& rhs) const;
	Mystring& operator+=(const Mystring& rhs);
	Mystring operator*(int n)const;
	Mystring& operator*=(int n);
	void display()const;
	int getLenght()const;
	const char* getStr()const;
};

