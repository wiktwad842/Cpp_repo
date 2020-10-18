#pragma once
class Mystring {
private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(const Mystring& source);
	~Mystring();
	void display()const;
	int getLenght()const;
	const char* getStr()const;
};


