#include <iostream>
#include <cmath>

int main() {
	int x1, y1, x2, y2, r, R;
	setlocale(LC_ALL, "russian");

	std::cout << "Set x1: ";
	std::cin >> x1;
	std::cout << "Set y1: ";
	std::cin >> y1;
	std::cout << "Set x2: ";
	std::cin >> x2;
	std::cout << "Set y2: ";
	std::cin >> y2;
	std::cout << "Set r: ";
	std::cin >> r;
	std::cout << "Set R: ";
	std::cin >> R;

	double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (dist > r + R) {
		std::cout << "Ни одно условие не выполнено";
	}
	else if (R > dist + r) {
		std::cout << "Да";
	}
	else if (r > dist + R) {
		std::cout << "Да, но справедливо обратное для двух фигур";
	}
	else {
		std::cout << "Фигуры пересекаются";
	}

	return 0;
}