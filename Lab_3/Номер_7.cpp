#include <iostream>

auto Input_check(double x) {  // change type
	bool input = true;

	do {

		std::cout << "Enter x: "; // Change x
		std::cin >> x;


		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		else input = false;


	} while (input);

	return x; // change
}
double my_sin(double x) {
	double sina = 0;
	int sign = 1;
	
	x = fmod(x, 2 * 3.14159265359);

	for (int k = 0; k <= 100; k++) {


		if (k % 2 == 0) {
			sign = 1;
		}
		else {
			sign = -1;
		}

		double factorial = 1;
		double numenator = x;

		for (int i = 1; i <= k; i++) {
			numenator *= x * x;
			factorial *= (2 * i) * (2 * i + 1);
		}

		sina += sign * numenator / factorial;
	}
	return sina;
}
double my_cos(double x) {
	double cosi = 0;

	x = fmod(x, 2 * 3.14159265359);

	int sign = 1;
	for (int k = 0; k <= 100; k++) {


		if (k % 2 == 0) {
			sign = 1;
		}
		else {
			sign = -1;
		}

		double factorial = 1;
		double numenator = 1;

		for (int i = 1; i <= k; i++) {
			numenator *= x * x;
			factorial *= (2 * i) * (2 * i - 1);
		}

		cosi += sign * numenator / factorial;
	}
	return cosi;
}
double my_log(double x) {
	x = (x - 1) / (1 + x);
	double result = 0;


	double degree = x;
	double denominator = 1;
	for (int i = 0; i < 100; i++) {
		result += degree / (2 * i + 1);
		degree *= x * x;

	}

	return 2 * result;
}

int main() {
	double a, b, c, x = 0;
	x = Input_check(x);

	a = my_sin(x);
	b = my_cos(x);
	
	x = x > 0 ? x : -x;	
	
	c = my_log(x);


	if (a <= b && a <= c) 
	{
		std::cout << "Sin(x) is the smallest: " << a;
	}
	else if (b <= a && b <= c) 
	{
		std::cout << "Cos(x) is the smallest: " << b;
	}
	else
	{
		std::cout << "ln|x| is the smallest: " << c;
	}
	return 0;
}