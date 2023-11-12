#include <iostream>

#include "..\Staticlab_1\Liba.h"

double Input_check_float() {

	bool input = false, dot_check = true;
	std::string str;
	double num = 0, size;				     //                              ?
	int length_before = 0, length_after = 0; // before and after . or , (1123.324354)
	//								 ?
	std::cout << "Input float number: ";

	do {


		std::cin >> str;

		size = str.size();

		dot_check = true;
		input = false;
		for (int i = 0; i < size; i++) {

			if ((int)str[i] == 46) {

				dot_check = false;

			}

			if (((int)str[i] < 48 || (int)str[i] > 57) && ((int)str[i] != 46)) {
				input = true;

				std::cout << "Do you know what float means?\n";

				break;
			}
		}

		if (!input && dot_check) {

			std::cout << "There must be a dot (.)\n";

		}

		if (!input && !dot_check) {

			length_before = 0;
			while (str[length_before] != '.') {

				length_before++;

			}

			//length_after = size - length_before - 1; // length_before - 1 as we need to ignore . or ,





		}

	} while (input || dot_check);


	for (int i = 0; i < length_before; i++) {

		num += (str[i] - 48) * pow(10, length_before - i - 1);

	}
	int degree = -1;
	for (int i = length_before + 1; i < size; i++, degree--) { // length_before - 1 as we need to ignore . or ,

		num += (str[i] - 48) * pow(10, degree);

	}


	return num;

}
int Input_check() {

	bool input = false;
	std::string str;
	int num = 0;
	int size;
	do {

		std::cout << "Input integer number: ";
		std::cin >> str;


		size = str.size();


		input = false;
		for (int i = 0; i < size; i++) {

			if ((int)str[i] < 48 || (int)str[i] > 57) {
				input = true;

				std::cout << "Do you know what integer is?\n ";

				break;
			}
		}


	} while (input);


	for (int i = 0; i < size; i++) {

		num += (str[i] - 48) * pow(10, size - i - 1);

	}


	return num;
}

double **alloc_mem(int N, int M) {

	double** matrix = new double* [N];

	for (int i = 0; i < N; i++) {
		matrix[i] = new double[M];
		
	}
	return matrix;
}

double Input_check_num(double number, int i, int j) {  // change type
	bool input = true;

	do {

		std::cout << "Enter element[" << i << "][" << j << "]: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}
double fulfill_matrix(int N, int M, double** matrix) {
	int num = 0, j;
	for (int i = 0; i < N; i++) {
		j = 0;
		for (double* p = matrix[i]; p < matrix[i] + M; p++, j++) {

			*p = Input_check_num(num, i, j);

		}
	}
	return **matrix;
}

int search_for_zeros(double** matrix, int N, int M) {

	int counter = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) {
				counter++;
			}
		}
	}
	return counter;
}
void print_zeros(double** matrix, int N, int M, int counter) {
	
	if (counter != 0) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (matrix[i][j] == 0) {
					std::cout << "There is a zero with indexes: " << i << " " << j << "\n";
				}
			
			}
		}	
		std::cout << "Total number of zeros: " << counter << "\n";
	}
	else {
		std::cout << "No zeros found";
	}
}

void print_vice_matrix(double** matrix, int N, int M) {

	std::cout << "New matrix:\n";

	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {

			std::cout << matrix[i][j] << " ";

		}
		std::cout << "\n";
	}

}
void print_matrix(int n, int m, double** matrix) {
	
	std::cout << "matrix:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			std::cout << matrix[i][j] << " ";
		
		}
		std::cout << "\n";
	}
}

void delete_matrix(double** matrix, int n) {

	for (int i = 0; i < n; i++) {

		delete[] matrix[i];
		matrix[i] = nullptr;

	}

	delete matrix;
	matrix = nullptr;

}


int main() {

	std::cout << "N: 4\nTask: Count number of zeros and replace elements of matrix vice-versa        \n";

	bool input = true;

	do {

		int N = 0, M = 0;
		
		
		N = Input_check();		
		M = Input_check();

		double **matrix = alloc_mem(N, M);
		**matrix = fulfill_matrix(N, M, matrix);

		int counter = search_for_zeros(matrix, N, M);
		
		
		print_matrix(N, M, matrix);
		print_vice_matrix(matrix, N, M);
		

		print_zeros(matrix, N, M, counter);


		delete_matrix(matrix, N);


		std::cout << "\n";
		std::cout << "If you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = true;
		}

	} while(input);


	return 0;
}