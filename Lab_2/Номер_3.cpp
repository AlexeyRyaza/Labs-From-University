#include <iostream>

int main() {
	int x, y;
	std::cout << "Set x: ";
	std::cin >> x;
	std::cout << "Set y: ";
	std::cin >> y;

	if (x < y) {
		x = 0;
	}
	else if (x > y) {
		y = 0;
	}
	else {
		x = 0;
		y = 0;
	}


	double a, b, c, k;
	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b: ";
	std::cin >> b;
	std::cout << "Set c: ";
	std::cin >> c;
	std::cout << "Set k: ";
	std::cin >> k;

	if(a > b && a > c){
		a -= k;
	}
	else if (b > a && b > c) {
		b -= k;
	}
	else {
		c -= k;
	}

	std::cout << "x = " << x << "\n";
	std::cout << "y = " << y << "\n";

	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";


	return 0;
}