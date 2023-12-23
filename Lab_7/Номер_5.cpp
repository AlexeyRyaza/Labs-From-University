#include <iostream>

int main() {
	int t, num;
	std::cin >> t;

	int answer;
	for (int i = 0; i < t; ++i) {
		std::cin >> num;

		answer = (num + 1) / 10;
		std::cout << answer << "\n";
	}
}