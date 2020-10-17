#include <iostream>
#include <vector>
using namespace std;





class Movie {
	
	
private:
	
	string name;
	string rating;
	int watched;
	friend class Movies;
public:

	void incrementWatched() {
		this->watched++;
	}
	
	//contructor
	Movie(string nameVal, string ratingVal,int watched);
	//destructor
	~Movie();

};

Movie::Movie(string nameVal,string ratingVal,int watchedVal)
	: name{ nameVal }, rating{ ratingVal }, watched{watchedVal}{
}
Movie::~Movie() {

}

class Movies {

private:
	std::vector<Movie>movies;
public:

	bool addMovie(string nameVal, string ratingVal, int watchedVal);

	Movies();
	~Movies();

};

bool addMovie(string nameVal, string ratingVal, int watchedVal) {
	return true;
}

Movies::Movies()
	:movies() {
}
Movies::~Movies() {

}


int main() {

	Movies();



	return 0;
}