#include <iostream>
#include <stdlib.h>

auto Input_check(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter n: "; // Change x
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
	std::cout << "№ 9 \nВариант: 6 \nЗадание: Найти сумму наибольшей диагонали куба(без использования вложеных циклов) \n";

	
	do {
		int n = 0, num, d1 = 0, d2 = 0, d3 = 0, d4 = 0, max1, max2;


		n = Input_check(n);


		int*** a = NULL;
		a = (int***)malloc(n * sizeof(int));


		for (int i = 0; i < n; i++) {
			a[i] = (int**)malloc(n * sizeof(int));
			for (int j = 0; j < n; j++) {
				a[i][j] = (int*)malloc(n * sizeof(int));
				for (int k = 0; k < n; k++) {
					std::cin >> num;
					a[i][j][k] = num;
				}
			}
		}


		for (int i = 0; i < n; i++) {
			d1 += a[i][i][i];
			d2 += a[n - i - 1][i][i];
			d3 += a[i][n - i - 1][i];
			d4 += a[n - 1 - i][n - i - 1][i];
		}

		max1 = std::max(d1, d2);
		max2 = std::max(d3, d4);

		max1 = std::max(max1, max2);

		std::cout << "The sum of the largest diagonal is: " << max1;




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				free(a[i][j]);
				a[i][j] = NULL;
			}
		}

		std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = 1;
		}

	} while (input);



	return 0;
}