#include <iostream>

auto Input_check_n(double n) {
	bool input = true;

	do {

		std::cout << "Enter n: ";
		std::cin >> n;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return n;
}
auto Input_check_m(double m) {
	bool input = true;

	do {

		std::cout << "Enter number of x: ";
		std::cin >> m;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return m;
}

int main() {
	double degree, factorial, Y, x, S, n = 0, m = 0;
	const long double e = 2.71828182845904523536;
	
	n = Input_check_n(n);
	m = Input_check_m(m);
	
	for (int i = 1; i <= m; i++) {
		std::cout << "Set x: ";
		std::cin >> x;
		Y = (pow(e, x) - pow(e, -x)) / 2; 

		S = 0;
		factorial = 1;
		degree = x;

		for (int j = 1; j <= n; j++) {
			
			S += degree / factorial;
			degree *= x * x;		
			factorial *= (2 * j) * (2 * j + 1);
			
		}

		std::cout << "When x = " << x << ":" << "\n";
		std::cout << "Y = " << Y << "\t" << "S = " << S << "\n" << "\n";
	
	}

}