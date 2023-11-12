#include <iostream>
#include <iomanip>


int main() {
	long long K;
	std::cin >> K;
	setlocale(LC_ALL, "russian");

	if ((K % 10 >= 5 && K % 10 <= 9) || (K % 100 >= 5 && K % 100 <= 20) || K % 10 == 0) {
		std::cout << "Мы нашли " << K << " грибов в лесу";
	}
	else if ((K % 10 >= 2 && K % 10 <= 4)) {
		std::cout << "Мы нашли " << K << " гриба в лесу";
	}
	else if (K % 10 == 1) {
		std::cout << "Мы нашли " << K << " гриб в лесу";
	}

	return 0;
}