#include <iostream>
#include <cmath>

int main() {
	double D, x;
	std::cout << "Set D: ";
	std::cin >> D, "\n";
	std::cout << "Set x: ";
	std::cin >> x, "\n";

	double numerator = pow((D * x), 2) + pow((x + D), 3) * cos(x);
	double denominator = (x + D) * pow(D, 3) * (D + x - pow(x, 2));
	double S = numerator / denominator;

	std::cout << "S = " << S;


	return 0;
}