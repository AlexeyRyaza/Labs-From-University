#include <iostream>
#include "..\Staticlab_1\Liba.h"


int main() {
	
	int input = 1;

	std::cout << "N: 1\nTask: Calculate multiplication of two arrays\n";

	do {

		int n = 0;

		std::cout << "Enter n: ";
		n = Input_check();

		double* X = alloc_mem(n);
		*X = fullfil_X(X, n);

		double* Y = alloc_mem(n);
		*Y = create_Y(Y, n);

		double* C = alloc_mem(n);
		*C = multiplication(X, Y, C, n);


		std::cout << "Multiplication of two arrays: ";
		print_mass(C, n);
		std::cout << "\n";


		std::cout << "Array Y: ";
		print_mass(Y, n);
		std::cout << "\n";

		delete_mass(X);
		delete_mass(Y);
		delete_mass(C);


		std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = 1;
		}

	} while (input);

	return 0;
}