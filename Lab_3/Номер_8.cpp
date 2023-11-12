#include <iostream>
#include <cmath>

auto Input_check(int num) {  // change type
	bool input = true;

	do {

		std::cout << "Set number: "; // Change x
		std::cin >> num;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return num;
}


int main() {
	int num = 0;
	num = Input_check(num);
	
	int last_digit;

	for (int j = 1; j <= num; j++) {


		int counter = 0;
		int sum = 0;
		int k = j;
		int l = j;
		int check = j;

		while (k != 0) {
			counter += 1;
			k /= 10;
		}
		
		for (int i = 1; i <= counter; i++) {
			last_digit = l % 10;
			sum += pow(last_digit, counter);

			l /= 10;
		}

		if (sum == check) {
			std::cout << "We found number: " << sum << "\n";
		}

	}
	return 0;
}