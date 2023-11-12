#include <iostream>

auto Input_check_N(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter N: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}
auto Input_check_M(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter M: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}
auto Input_check_num_A(int number, int i, int j) {  // change type
	bool input = true;

	do {

		std::cout << "Enter element[" << i << "][" << j << "] of matrix A: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}
auto Input_check_num_B(int number, int i, int j) {  // change type
	bool input = true;

	do {

		std::cout << "Enter element[" << i << "][" << j << "] of matrix B: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}





int main() {
	int N = 0, M = 0, num_A = 0, num_B = 0, sum = 0, j;


	N = Input_check_N(N);
	M = Input_check_M(M);


	int** a = new int* [N];
	int** b = new int* [M];
	int** c = new int* [N];

	for (int i = 0; i < N; i++) { // matrix A (NxM)
		a[i] = new int [M];
		j = 0;
		for (int* p = a[i]; p < a[i] + M; p++, j++) {
			*p = Input_check_num_A(num_A, i, j);
		}
	}


	for (int i = 0; i < M; i++) { // matrix B (MxN)
		b[i] = new int[N];
		j = 0;
		for (int* p = b[i]; p < b[i] + N; p++, j++) {
			*p = Input_check_num_B(num_B, i, j);
		}
	}


	for (int i = 0; i < N; i++) {  // Matrix C (NxN)
		c[i] = new int[N];
	}


	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			sum = 0;

			for (int j = 0; j < M; j++) {
				sum += a[k][j] * b[j][i];
			}

			c[k][i] = sum;
		
		}
		
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << c[i][j] << " ";
		}
		std::cout << "\n";

	}

	for (int i = 0; i < N; i++) {
		delete[] a[i];
		delete[] c[i];

		a[i] = nullptr;
		c[i] = nullptr;
	}

	for (int i = 0; i < M; i++) {
		delete[] b[i];
		b[i] = nullptr;
	}

	a = nullptr;
	b = nullptr;
	c = nullptr;

	return 0;
}