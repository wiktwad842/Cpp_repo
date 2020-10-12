#include <iostream>

using namespace std;

class Shallow {
private:
	int* data;
public:
	void setDataValue(int d) {
		*data = d; 
	}
	int getDataValue() {
		return *data;
	}
	//Constructor
	Shallow(int d);
	//Copy Constructor
	Shallow(const Shallow& source);
	//Destructor
	~Shallow();
};

Shallow::Shallow(int d) {
	data = new int;
	*data = d;
}
Shallow::Shallow(const Shallow& source) 
	:data(source.data) {
		cout << "Copy Constructor - shallow copy" << endl;
	}
Shallow::~Shallow() {
	delete data;
	cout << "Destructor freeing data" << endl;
}
void displayShallow(Shallow s) {
	cout << s.getDataValue() << endl;
}




int main() {
	Shallow obj1{ 100 };
	displayShallow(obj1);
	return 0;
}