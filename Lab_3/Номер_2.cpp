#include <iostream>
#include <cmath>
#include <iomanip>

auto Input_check(long double number) {
    bool input = true;

    do {

        std::cout << "Set n: ";
        std::cin >> number;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number;
}


int main() {
	long double n = 0, i = 1, sum = 0;
    n = Input_check(n);
	
    do {

		sum += pow(0.5, i) + pow(1.0 / 3, i);
		i++;
	} while (pow(0.5, i) + pow(1.0 / 3, i) >= 0.001);

	std::cout << "Sum = " << std::setprecision(4) << sum;
}