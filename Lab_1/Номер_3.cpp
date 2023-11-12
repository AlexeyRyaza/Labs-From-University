#include <iostream>

int main() {
	double v0, t, s, a;
	std::cout << "Set t: ";
	std::cin >> t, "\n";
	std::cout << "Set v0: ";
	std::cin >> v0, "\n";
	std::cout << "Set a: ";
	std::cin >> a, "\n";

	s = v0 * t + a / 2 * pow(t, 2);
	std::cout << "Distant = " << s;


	return 0;
}