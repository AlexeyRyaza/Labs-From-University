#include <iostream>
#include <stdlib.h>

auto Input_check_N(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter number of rows: "; // Change x
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

		std::cout << "Enter number of columns: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}

bool input = true;

int main() {

	setlocale(LC_ALL, "Russian");
	std::cout << "№ 11 \nВариант: 6 \nЗадание: Требуется дополнить введенное поле сапера числами, как в оригинальной игре \n";


	do {

		int n = 0, m = 0, counter = 0;
		char element;

		n = Input_check_N(n);
		m = Input_check_M(m);

		char** a = NULL;
		a = (char**)malloc(n * sizeof(char*));

		for (int i = 0; i < n; i++) {
			a[i] = (char*)malloc(m * sizeof(char));
			for (char* p = a[i]; p < a[i] + m; p++) {
				std::cin >> element;
				*p = element;
			}
		}

		std::cout << "\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				counter = 0;

				if (a[i][j] == '*') {
					std::cout << '*' << " ";
				}
				else {
					if (i - 1 >= 0) {

						if (a[i - 1][j] == '*') {
							counter++;
						}
						if (j - 1 >= 0 && (a[i - 1][j - 1] == '*')) {
							counter++;
						}
						if (j + 1 < m && (a[i - 1][j + 1] == '*')) {
							counter++;
						}
					}

					if (i + 1 < n) {

						if (a[i + 1][j] == '*') {
							counter++;
						}
						if (j - 1 >= 0 && (a[i + 1][j - 1] == '*')) {
							counter++;
						}
						if (j + 1 < m && (a[i + 1][j + 1] == '*')) {
							counter++;
						}

					}

					if (j - 1 >= 0 && (a[i][j - 1] == '*')) {
						counter++;
					}

					if (j + 1 < m && (a[i][j + 1] == '*')) {
						counter++;
					}

					std::cout << counter << " ";

				}

			}

			std::cout << "\n";

		}

		for (int i = 0; i < n; i++) {
			free(a[i]);
			a[i] = NULL;
		}

		//free(a);
		//a = NULL;


		std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = true;
		}

	} while (input);




	return 0;
}