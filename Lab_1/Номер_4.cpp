#include <iostream>

int main() {
	double b1, q,  s;
	std::cout << "Set b1: ";
	std::cin >> b1, "\n";

	q = (double)1 / 22; // my number: 21
	s = b1 / (1 - q);


	std::cout << "S = " << s;

	return 0;
}