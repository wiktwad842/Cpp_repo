#include <iostream>
#include <vector>
using namespace std;

class Move {
private:
	int* data;
public:
	void setDataValue(int d) {
		*data = d;
	}
	int getDataValue() {
		return *data;
	}
	Move(int d);
	Move(const Move &source);
	Move(Move&& source) noexcept;
	~Move();
};

Move::Move(int d) {
	data = new int;
	*data = d;
	cout << "Constructor for: " << d << endl;
}

Move::Move(Move &&source) noexcept
	:data{ source.data } {
		source.data = nullptr;
	}

Move::Move(const Move& source)
	:Move{*source.data}{
	cout << "Copy constructor - deep copy for: " << *data << endl;
}

Move::~Move() {
	if (data != nullptr) {
		cout << "Destructor freeing data for: " << *data << endl;
	}
	else {
		cout << "Destructor freeing data for nullptr" << endl;
	}
	delete data;
}


//Shallow::~Shallow() {
//	delete data;
//	cout << "Destructor freeing data" << endl;
//}
//void displayShallow(Shallow s) {
//	cout << s.getDataValue() << endl;
//}






int main() {

	vector<Move>vec;
	vec.push_back(Move{ 10 });
	vec.push_back(Move{ 20 });
	vec.push_back(Move{ 30 });
	vec.push_back(Move{ 40 });
	vec.push_back(Move{ 50 });
	vec.push_back(Move{ 60 });
	vec.push_back(Move{ 70 });

	vec.push_back(Move{ 80 });

	/*int x{ 100 };
	int& l_ref = x;
	l_ref = 10;

	int&& r_ref = 200;
	r_ref = 300;


	cout << x;*/
	return 0;
}