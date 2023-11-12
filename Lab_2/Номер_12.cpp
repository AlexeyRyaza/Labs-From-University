#include <iostream>

int main() {
	double a, b, c, x, y;
	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b: ";
	std::cin >> b;
	std::cout << "Set c: ";
	std::cin >> c;
	std::cout << "Set x: ";
	std::cin >> x;
	std::cout << "Set y: ";
	std::cin >> y;
	
	double square = x * y;


	if (a * b || a * c || b * c <= square) {
		std::cout << "Brick goes through";
	}
	else {
		std::cout << "Brick doesn't go through";
	}

	return 0;
}