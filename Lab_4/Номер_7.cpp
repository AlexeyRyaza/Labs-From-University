#include <iostream>

auto Input_check_n(int number) {  // change type
	bool input = true;

	do {

		std::cout << "Enter number number of elements: "; // Change x
		std::cin >> number;


		if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return number; // change
}
auto Input_check_num(int number, int i) {  // change type
	bool input = true;

	do {

		std::cout << "Enter element [" << i << "]: "; // Change x
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
	int n = 0, max, min, max_i, min_i, num = 0, rest;
	
	
	n = Input_check_n(n);


	int* a = new int[n];


	for (int i = 0; i < n; i++) {
		a[i] = Input_check_num(num, i);
	}


	min = INT_MAX;
	max = INT_MIN;
	for (int i = 0; i < n; i++) {

		if (a[i] < min) {
			min = a[i];
			min_i = i;
		}
	
		if (a[i] > max) {
			max = a[i];
			max_i = i;
		}


	}

	int temp = std::max(min_i, max_i);
	min_i = std::min(min_i, max_i);
	max_i = temp;	
	
	
	rest = max_i - min_i - 1;

	std::cout << "\nThe answer is: ";

	if (max_i - min_i >= n / 2) {
	

		int z = n + 1 - (max_i - min_i);
		int* b = new int[z];
		
		for (int i = 0; i <= min_i; i++) {
			b[i] = a[i];
		}

		for (int i = min_i + 1; i < rest; i++) {
			b[i] = a[i + rest];
		}
		
		for (int i = 0; i < z; i++) {
			std::cout << b[i] << " ";
		}

	}
	else {
		
		for (int i = min_i + 1; i < max_i; i++) {
			a[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}

	}

	delete[] a;
	a = nullptr;

	return 0;
}