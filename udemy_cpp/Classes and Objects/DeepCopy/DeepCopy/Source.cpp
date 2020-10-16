#include <iostream>

using namespace std;

class Deep {
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
	Deep(int d);
	//Copy Constructor
	Deep(const Deep& source);
	//Destructor
	~Deep();
};

Deep::Deep(int d) {
	data = new int;
	*data = d;
}
Deep::Deep(const Deep& source) {
	data = new int;
	*data = *source.data;
	cout << "Copy Constructor - deep copy" << endl;
}
Deep::~Deep() {
	delete data;
	cout << "Destructor freeing data" << endl;
}
void displayShallow(Deep s) {
	cout << s.getDataValue() << endl;
}




int main() {
	Deep obj1{ 100 };
	displayShallow(obj1);

	Deep obj2(obj1);
	obj2.setDataValue(1000);
	return 0;
}