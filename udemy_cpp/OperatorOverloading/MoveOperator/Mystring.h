#pragma once
class Mystring {
private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(const Mystring& source);
	//Mystring(Mystring&& source);
	Mystring& operator=(const Mystring& rhs); //copy assignment
	Mystring& operator=(Mystring&& tempStr);  //move assignment
	Mystring operator-()const;				  //lower case 
	Mystring operator+(const Mystring& strToAdd)const ; //append
	bool operator==(const Mystring& rhs)const; //equality
	~Mystring();
	void display()const;
	int getLenght()const;
	const char* getStr()const;
};