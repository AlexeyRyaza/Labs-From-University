#include <iostream>
#include <cmath>

int main() {
	double r, p, q;
	std::cout << "Set Radius: ";
	std::cin >> r;
	std::cout << "Set length of side: ";
	std::cin >> p;
	std::cout << "Set angle's degree: ";
	std::cin >> q;
	
	
	double P = 2 * p;
	double s = pow(p, 2) * sin(q * acos(-1) / 180);
	double check = s / P;

	
	if (check <= r) {
		std::cout << "It goes through!";
	}
	else {
		std::cout << "It doesn't go through";
	}

	return 0;
}