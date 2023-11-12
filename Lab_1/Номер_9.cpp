#include <iostream>

int main() {
	int a, b;
	std::cout << "Set a: ";
	std::cin >> a, "\n", "\n";

	std::cout << "Set b: ";
	std::cin >> b, "\n";

	a = a ^ b;
	std::cout << "First swap: a = " << a << "; b = " << b << "\n";
	
	b = a ^ b;
	std::cout << "Second swap: a = " << a << "; b = " << b << "\n";

	a = a ^ b;
	std::cout << "Final swap: a = " << a << "; b = " << b;
		
	return 0;
}