#include <iostream>
#include <cmath>

auto Input_check_B(double B) {
	bool input = true;

	do {

		std::cout << "Enter B: ";
		std::cin >> B;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return B;
}
auto Input_check_A(double A) {
	bool input = true;

	do {

		std::cout << "Enter A: ";
		std::cin >> A;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return A;
}
auto Input_check_M(double M) {
	bool input = true;

	do {

		std::cout << "Enter M: ";
		std::cin >> M;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return M;
}



int main() {
	double x, y, i, H, B = 0, A = 0, M = 0;
	
	B = Input_check_B(B);
	A = Input_check_A(A);
	M = Input_check_M(M);

	H = (B - A) / M;
	
	for (i = 0; i < M; i++) {
		x = A + i * H;
		y = sin(x) - cos(x);
		
		std::cout << "Y" << i << " : " << y << "\t" << "X" << i << ": " << x << "\n";

	}

	return 0;
}