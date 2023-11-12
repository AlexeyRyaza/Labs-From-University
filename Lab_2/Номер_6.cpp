#include <iostream>

int main() {
	double a, b, c, d, z;

	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b: ";
	std::cin >> b;
	std::cout << "Set c: ";
	std::cin >> c;
	std::cout << "Set d: ";
	std::cin >> d;

	if (c >= d && a < d) {
		z = a + b / c;
	}
	else if(c < d && a >= d) {
		z = a - b / c;
	}
	else {
		z = 0;
	}

	std::cout << "z = " << z;












	return 0;
}