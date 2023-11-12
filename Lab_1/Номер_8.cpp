#include <iostream>

int main() {
	int h1, min1, h2, min2;
	std::cout << "Time when he started: " << "\n";
	
	std::cout << "Hours: ";
	std::cin >> h1, "\n";
	std::cout << "Minutes: ";
	std::cin >> min1;


	std::cout << "\n" << "Time when he finished: " << "\n";
	
	std::cout << "hours: ";
	std::cin >> h2, "\n";
	std::cout << "minutes: ";
	std::cin >> min2, "\n";


	int time1 = h1 * 60 + min1;
	int time2 = h2 * 60 + min2;
	int diffrence = time2 - time1;
	int only_hours = diffrence / 60;
	std::cout << "Time spent: " << "\n";
	std::cout << diffrence / 60 << " hours" << "\n";
	std::cout << diffrence % (only_hours * 60) << " minutes";

	return 0;
}