#include <iostream>

auto Input_check(int n) {
	bool input = true;

	do {

		std::cout << "Enter n: ";
		std::cin >> n;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return n;
}


int main() {
	int n = 0, i, sum = 0;;

	n = Input_check(n);
	
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum += i;
		}
	}

	std::cout << "Sum with for: " << sum << "\n";


	sum = 0; 
	i = 1;

	label:
	if (i <= n) {
		if (i % 2 == 0) {
			sum += i;
		}

		i++;
		goto label;
	}

	std::cout << "Sum without for: " << sum;
}