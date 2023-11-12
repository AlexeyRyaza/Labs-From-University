#include <iostream>
#include <cmath>

int main() {
	double h, time, g = 9.81;

	std::cout << "height: ";
	std::cin >> h, "\n";
	
	time = sqrt(2 * h / 9.81);
	
	std::cout << "falling time: " << time;

	return 0;
}