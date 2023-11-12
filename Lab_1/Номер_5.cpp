#include <iostream>

int main() {
	double a1, a100, s, d; // sum of first 31 
	std::cout << "Set a1: ";
	std::cin >> a1, "\n";
	std::cout << "Set a100: ";
	std::cin >> a100, "\n";

	d = (a100 - a1) / (100 - 1);
	s = (2 * a1 + d * 30) * ((double)31 / 2);

	std::cout << "d = " << d << "\n";
	std::cout << "s = " << s;

	return 0;
}