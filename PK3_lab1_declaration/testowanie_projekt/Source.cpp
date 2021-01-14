#include <vector>
#include <iostream>
using namespace std;

void print( vector<vector<double>> wek) {
	for (int i = 0; i < wek.size(); i++) {
		for (int j = 0; j < wek.front().size(); j++) {
			cout << wek[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<double>> augment_matrix(vector<vector<double>> matrix_A,vector<double> vector_B) {
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

bool gaussian_elimination(vector<vector<double>> &augmented_matrix) {
	for (int i = 0; i < augmented_matrix.size() - 1; i++) {
		for (int k = i + 1; k < augmented_matrix.size(); k++)
		{
			double temp;
			temp = augmented_matrix[k][i] / augmented_matrix[i][i];
			for (int j = 0; j < augmented_matrix.size()+1; j++) {
				augmented_matrix[k][j] = augmented_matrix[k][j] - temp * augmented_matrix[i][j];
			}
		}
	}
	
	return true;
}
int forwardElim(double mat[N][N + 1])
{
	for (int k = 0; k < N; k++)
	{

		int i_max = k;
		int v_max = mat[i_max][k];

		for (int i = k + 1; i < N; i++)
			if (abs(mat[i][k]) > v_max)
				v_max = mat[i][k], i_max = i;
		if (!mat[k][i_max])
			return k; 
		if (i_max != k)
			swap_row(mat, k, i_max);
		for (int i = k + 1; i < N; i++)
		{

			double f = mat[i][k] / mat[k][k];


			for (int j = k + 1; j <= N; j++)
				mat[i][j] -= mat[k][j] * f;

			mat[i][k] = 0;
		}

		
	}

	return -1;
}
int main() {

	vector <vector <double> > matrix_A;
	vector <double> vector_B;
	vector <vector <double> > augmented_matrix;

	vector <double> line_1;
	vector <double> line_2;
	vector <double> line_3;


	vector_B.push_back(-3);
	vector_B.push_back(20);
	vector_B.push_back(30);

	line_1.push_back(1);
	line_1.push_back(2);
	line_1.push_back(5);

	line_2.push_back(2);
	line_2.push_back(-4);
	line_2.push_back(-10);

	line_3.push_back(5);
	line_3.push_back(8);
	line_3.push_back(9);

	/*vector_B.push_back(5);
	vector_B.push_back(20);

	line_1.push_back(3);
	line_1.push_back(-2);


	line_2.push_back(2);
	line_2.push_back(-8);*/


	matrix_A.push_back(line_1);
	matrix_A.push_back(line_2);
	matrix_A.push_back(line_3);

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
	return 0;
}