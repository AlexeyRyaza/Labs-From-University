#include < iostream>

int main() {
	unsigned int x, y, z;
	std::cout << "Set x: ";
	std::cin >> x;
	std::cout << "Set y: ";
	std::cin >> y;
	std::cout << "Set z: ";
	std::cin >> z;

	if ((x + y > z) && (x + z > y) && (z + y > x)) {
		std::cout << "Such triangle exist";
	}
	else {
		std::cout << "Such triangle doesn't exist";
	}
	
	return 0;
}