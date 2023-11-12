#include <iostream>

int main() {
	double x, y, z;
	bool flag;
	std::cin >> x >> y;

	z = x > y ? x : y;
	std::cout << "Without bool: " << z << "\n";

	flag = x > y;

	std::cout << flag ? x : y;
}