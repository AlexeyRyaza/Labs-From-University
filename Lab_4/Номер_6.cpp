#include <iostream>

auto Input_check_n(long long number) {  // change type
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
auto Input_check_z(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter i: "; // Change x
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
	long long n = 0, length = 0, counter = 0, last_digit, z = 0;
	bool flag = true;

	n = Input_check_n(n);
	z = Input_check_z(z);

	long long temp = n;

	while (temp != 0) {
		length += 1;
		temp /= 10;
	}

	//std::cout << "length: " << length << "\n";

	int* a = new int [length];

	for (int i = length - 1; i >= 0; i--) {
	
		last_digit = n % 10;
		a[i] = last_digit;
		n /= 10;		
	}
	
	for (int i = 0; i < length; i++) {
		
	}


	for (int i = 0; i < length; i++) {
		flag = true;
		for (int j = 0; j < i; j++) {
			
			if (a[i] == a[j]) {
				flag = false;				
			}

		}
		
		if (flag == true) {
			counter += 1;
		}

	}


	std::cout << "Amount of unique digits: " << counter << "\n";
	
	std::cout << "indexes of searches number are: ";
	
	for (int i = 0; i < length; i++) {
		
		if (z == a[i]) {
			std::cout << length - i - 1 << " ";
		}
	
	}

	delete[] a;
	a = nullptr;

	return 0;
}