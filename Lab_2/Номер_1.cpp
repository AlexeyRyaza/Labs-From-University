#include <iostream>

int main() {
	int x, y;
	std::cout << "Set x : ";
	std::cin >> x;
	std::cout << "Set y : ";
	std::cin >> y;

	if (x == 0 || y == 0) {
		std::cout << "ERROR";
	}
	else if (x % y == 0 || y % x == 0) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	
	return 0;
}