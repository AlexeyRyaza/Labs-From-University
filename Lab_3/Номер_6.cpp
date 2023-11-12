#include <iostream>
#include <cmath>

auto Input_check(double n) {
	bool input = true;

	do {

		std::cout << "On how many parts do we divide line?" << "\n";
		std::cin >> n;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return n;
}


int main() {
	double n = 0, answer, min, F;  // arccos(e ^ -x) - 2sinx
	const long double e = 2.71828182845904523536;
	n = Input_check(n);

	long double step = 2.0 / n ;
	answer = 10;
	min = 1000;
	const long double E = 3 + 1E-10;


	for (long double x = 1; x <= E; x += step) { // ?		

		F = acos(pow(e, -x)) - (2 * sin(x));

		if (abs(F) < min) {
			answer = x;
			min = abs(F);
		}
	}

	std::cout << "Answer approximately: " << answer << "\n";
	std::cout << "min: " << min;

}