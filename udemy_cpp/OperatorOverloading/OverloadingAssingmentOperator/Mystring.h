#pragma once
class Mystring {
private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(const Mystring& source);
	Mystring& operator=(const Mystring& rhs); //copy assignment
	//Mystring& operator=(Mystring&& tempStr);
	//Mystring& operator+(const Mystring& strToAdd);
	~Mystring();
	void display()const;
	int getLenght()const;
	const char* getStr()const;
};


