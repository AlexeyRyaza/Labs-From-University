#include <iostream>
#include <cmath>


int main() {
	int n, elem;

	std::cin >> n;
	
	elem = ceil(sqrt(n));

	if (n >= pow(elem, 2) - elem + 1) {
		std::cout << elem - 1 << " " << pow(elem, 2) - n << "\n";
	}

	else {
		std::cout << elem - (pow(elem, 2) - n - elem) - 2 << " " << elem - 1;

	}
	return 0;
}











































