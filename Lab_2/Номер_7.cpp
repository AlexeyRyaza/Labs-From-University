#include <iostream>


int main() {
	double a, b, c, y;
	int n;
	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b: ";
	std::cin >> b;
	std::cout << "Set c: ";
	std::cin >> c;
	std::cout << "Set n: ";
	std::cin >> n;

	switch (n) {
		case 2:
			y = b * c - a * a;
			break;
		case 3:
			y = a - b * c;
			break;
		case 7:
			y = a * a + c;
			break;
		case 56:
			y = b * c;
			break;
		default:
			y = pow(a + b, 3);
			break;
	
	}

	std::cout << "Y = " << y;


	return 0;
}