#include <iostream>


int main() {
	double a, b, z, y, x, f;
	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b : ";
	std::cin >> b;
	std::cout << "Set z: ";
	std::cin >> z;

	if (z < -1) {
		x = -z / 3;
	}
	else if (z >= -1) {
		x = abs(z);
	}
	
	std::cout << "Which funcion do we choose?" << "\n";
	std::cout << "1: f(x) = 2x" << "\n";
	std::cout << "2: f(x) = x ^ 3" << "\n";
	std::cout << "3: f(x) = x / 3" << "\n";

	int n;
	std::cin >> n;
	if (n > 3) {
		std::cout << "You could choose only 1, 2 or 3";
	}
	else {
		
		switch (n){
			case 1:
				std::cout << "We chose: f(x) = 2x" << "\n";
				f = 2 * x;
				std::cout << "f(x) = " << f << "\n";
				break;
			case 2:
				std::cout << "We chose: f(x) = x ^ 3" << "\n";
				f = pow(x, 3);
				std::cout << "f(x) = " << f << "\n";
				break;
			case 3:
				std::cout << "We chose: f(x) = x / 3" << "\n";
				f = x / 3;
				std::cout << "f(x) = " << f << "\n";
			default:
				break;
		}
	}

	y = a * f - log(x + 2.5) + b * (pow(2.71828, x) - pow(2.71828, -x));

	std::cout << "Y = " << y;



	return 0;
}