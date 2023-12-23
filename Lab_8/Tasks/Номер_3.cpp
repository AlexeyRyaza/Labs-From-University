// task: 1.11
#include <iostream>
#include <string>
#include <fstream>

#include "Functions_3.h"
#include "Class_3.h"

int main() {
	Student* list = new Student[100];
	int desicion = 0;

	do {
		std::cout << "\nWhat would you like to do:\nPress '0' to exit\nPress '1' to add new student\nPress '2' to change information about student\nPress '3' to print information about all students\nPress '4' to print information about exact student\nPress '5' to find out average score\nPress '6' to print students in sorted list\n";

		std::cin >> desicion;
		while (desicion < 0 || desicion > 6) {
			std::cout << "There is no such action\n";
			std::cin >> desicion;
		}

		Menu(list, desicion);
	} while (desicion);

	std::cout << "This is the end";
	
	delete[] list;

	return 0;
}
