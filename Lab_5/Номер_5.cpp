#include <iostream>

int Input_check() {

	bool input = false;
	std::string str;
	int num = 0;
	int length = 0;
	do {

		std::cin >> str;

		length = 0;
		while (str[length] != '\0') {

			length++;

		}


		input = false;
		for (int i = 0; i < length; i++) {

			if ((int)str[i] < 48 || (int)str[i] > 57) {
				input = true;

				std::cout << "TRY HARDER: ";

				break;
			}
		}


	} while (input);


	for (int i = 0; i < length; i++) {

		num += (str[i] - 48) * pow(10, length - i - 1);

	}


	return num;
}


int **alloc_mem(int N = 0, int M = 0) {

	int** matrix = new int* [N];

	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];

	}
	return matrix;
}

int Input_check_num(int number, int i, int j) {  // change type
	int input = 1;

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
int fullfill_matrix(int N, int M, int** matrix) {
	int num = 0, j;
	for (int i = 0; i < N; i++) {
		j = 0;
		for (int* p = matrix[i]; p < matrix[i] + M; p++, j++) {

			*p = Input_check_num(num, i, j);

		}
	}
	return **matrix;
}

int count_proper_nums(int n, int m, int** matrix) {

	int counter = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
		
			if (j % 2 != 0 && matrix[i][j] % 2 != 0) {
				counter++;
			}

		}
	}



	return counter;
}
int fullfill_array(int n, int m, int** matrix, int* array) {

	int counter = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (j % 2 != 0 && matrix[i][j] % 2 != 0) {
				array[counter] = matrix[i][j];
				counter++;
			}

		}


	}


	return *array;
}

double count_average(int counter, int* array) {
	double average = 0;

	for (int i = 0; i < counter; i++) {

		average += array[i];

	}

	average /= counter;

	return average;
}

void print_matrix(int n, int m, int** matrix) {

	std::cout << "matrix:\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			std::cout << matrix[i][j] << " ";

		}
		std::cout << "\n";
	}
}
void print_array(int counter, int* array) {

	std::cout << "Created array: ";

	for (int i = 0; i < counter; i++) {

		std::cout << array[i] << " ";

	}

}


void delete_matrix(int** matrix, int n) {

	for (int i = 0; i < n; i++) {

		delete[] matrix[i];
		matrix[i] = nullptr;

	}

	delete matrix;
	matrix = nullptr;

}
void delete_mass(int* array) {

	delete[] array;
	array = nullptr;

}


int main() {

	std::cout << "N: 5\nTask: Create new array of odd elements located on even columns";
	std::cout << " and calculete arithmetical avereage of this elements     \n";

	bool input = true;


	do {

		int n = 0, m = 0;

		std::cout << "Enter n: ";
		n = Input_check();
		std::cout << "Enter m: ";
		m = Input_check();


		int** matrix = alloc_mem(n, m);
		**matrix = fullfill_matrix(n, m, matrix);


		int counter = count_proper_nums(n, m, matrix);
		
		if (counter > 0) {

			int* array = new int[counter];


			*array = fullfill_array(n, m, matrix, array);


			double average = count_average(counter, array);

			std::cout << "\n";
			print_matrix(n, m, matrix);
			std::cout << "\n";
			print_array(counter, array);
			std::cout << "\nAverage value: " << average;


			delete_mass(array);
			delete_matrix(matrix, n);

		}
		else {
			std::cout << "No odd numbers on even columns\n";
		}
		
		


		std::cout << "\n";
		std::cout << "If you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = 1;
		}


	} while (input);







	return 0;
}