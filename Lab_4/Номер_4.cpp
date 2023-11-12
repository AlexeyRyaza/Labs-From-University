#include <iostream>

auto Input_check_elem(int number, int i, int j) {  // change type
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

int main() {
	
	
	
	
	int N = 0, M = 0, element = 0, min, counter = 0, j;
	N = Input_check_N(N);
	M = Input_check_M(M);

	int** a = new int* [N];

	for (int i = 0; i < N; i++) {
		a[i] = new int[M];
		j = 0;
		for (int* p = a[i]; p < a[i] + N; p++, j++) {
			*p = Input_check_elem(element, i, j);
		}


	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			min = INT_MAX;
			if (i - 1 >= 0) {
				min = std::min(min, a[i - 1][j]);

				if (j - 1 >= 0) {
					min = std::min(min, a[i - 1][j - 1]);
				}
				if (j + 1 < M) {
					min = std::min(min, a[i - 1][j + 1]);
				}
			}
			if (i + 1 < N) {
				min = std::min(min, a[i + 1][j]);
				if (j - 1 >= 0) {
					min = std::min(min, a[i + 1][j - 1]);
				}
				if (j + 1 < M) {
					min = std::min(min, a[i + 1][j + 1]);
				}
			}
			if (j - 1 >= 0) {
				min = std::min(min, a[i][j - 1]);
			}
			if (j + 1 < M) {
				min = std::min(min, a[i][j + 1]);
			}

			if (a[i][j] < min) {
				counter += 1;
			}
		}
	}
	std::cout << counter;

	for (int i = 0; i < N; i++) {
		delete[] a[i];
		a[i] = nullptr;
	}

	delete[] a;
	a = nullptr;

	return 0;
}