#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

void print( vector<vector<double>> wek) {
	for (int i = 0; i < wek.size(); i++) {
		for (int j = 0; j < wek.front().size(); j++) {
			cout << wek[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<double>> augment_matrix(vector<vector<double>> &matrix_A,vector<double> &vector_B) {
	vector<vector<double>> augmented_matrix = matrix_A;
	for (int i = 0; i < augmented_matrix.size(); i++) {
		augmented_matrix[i].push_back(vector_B[i]);
	}
	return augmented_matrix;
}

void partial_pivoting(vector<vector<double>> &augmented_matrix) {
	for (int i = 0; i < augmented_matrix.size(); i++)
		for (int k = i + 1; k < augmented_matrix.size(); k++)
			if (abs(augmented_matrix[i][i]) < abs(augmented_matrix[k][i]))
			{
				vector<double> temp = augmented_matrix[i];
				augmented_matrix[i].swap(augmented_matrix[k]);
				augmented_matrix[k].swap(temp);
			}
}

void gaussian_elimination(vector<vector<double>> &augmented_matrix) {
	for (int i = 0; i < augmented_matrix.size() - 1; i++) {
        for (int k = i + 1; k < augmented_matrix.size(); k++) {
            double temp;
            temp = augmented_matrix[k][i] / augmented_matrix[i][i];
            for (int j = 0; j < augmented_matrix.size() + 1; j++) {
                augmented_matrix[k][j] = augmented_matrix[k][j] - temp * augmented_matrix[i][j];
            }
        }
    }
}
void read_matrix_from_file(string const &input_file,int amount_of_equations,vector<vector<double>>&matrix_A, vector<double> &vector_B){
    ifstream file(input_file);
    if(file.is_open()){
        for (int i=0;i<amount_of_equations;i++){
            vector<double>temp_vector;
            for(int j=0;j<amount_of_equations;j++){
                double temp_value;
                file >> temp_value;
                temp_vector.push_back(temp_value);
            }
            matrix_A.push_back(temp_vector);
        }
        for(int k = 0;k<amount_of_equations;k++){
            double temp_value;
            file>>temp_value;
            vector_B.push_back(temp_value);
        }

    }
}
int amount_of_equations(){
    int numLines = 0;
    string stream;
    ifstream input_file("input_file.txt");
    if(input_file.is_open()){
        string unused;
        while ( std::getline(input_file, unused) )
            ++numLines;
    }
    return numLines/2;
}
bool write_matrix_to_file(vector<vector<double>> &matrix){
    ofstream output_file ("example.txt");
    if (output_file.is_open()) {
        for (auto & i : matrix){
            for (auto j : i){
                output_file<< j << " ";
            }
            output_file<<"\n";
        }
        return true;
    }
    else {
        cout << "Unable to open file";
        return false;
    }
}
// int forwardElim(double mat[N][N + 1])
// {
// 	for (int k = 0; k < N; k++)
// 	{

// 		int i_max = k;
// 		int v_max = mat[i_max][k];

// 		for (int i = k + 1; i < N; i++)
// 			if (abs(mat[i][k]) > v_max)
// 				v_max = mat[i][k], i_max = i;
// 		if (!mat[k][i_max])
// 			return k; 
// 		if (i_max != k)
// 			swap_row(mat, k, i_max);
// 		for (int i = k + 1; i < N; i++)
// 		{

// 			double f = mat[i][k] / mat[k][k];


// 			for (int j = k + 1; j <= N; j++)
// 				mat[i][j] -= mat[k][j] * f;

// 			mat[i][k] = 0;
// 		}

		
// 	}

// 	return -1;
// }
int main() {

	vector <vector <double> > matrix_A;
	vector <double> vector_B;
	vector <vector <double> > augmented_matrix;


    read_matrix_from_file("input_file.txt",amount_of_equations(),matrix_A,vector_B);
	print(matrix_A);
	cout << endl;
	augmented_matrix = augment_matrix(matrix_A, vector_B);
	cout << "augmented matrix: " << endl;
	print(augmented_matrix);
	cout << endl;
	partial_pivoting(augmented_matrix);
	cout << "after partial pivoting : " << endl;
	print(augmented_matrix);
	gaussian_elimination(augmented_matrix);
	cout << "after elimination : " << endl;
	print(augmented_matrix);
	cout << endl;
	cout << augmented_matrix.size();
	write_matrix_to_file(augmented_matrix);
	cout<<endl<<amount_of_equations();
	return 0;
}