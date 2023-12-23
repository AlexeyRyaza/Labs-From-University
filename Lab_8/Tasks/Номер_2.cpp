// task: 2.6
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Functions_2.h"
#include "Struct_2.h"

int main() {
	Student* list = new Student[100];
	int desicion = 0;

	do {
		std::cout << "\nWhat would you like to do:\nPress '0' to exit\nPress '1' to add new student\nPress '2' to change information about student\nPress '3' to print information about all students\nPress '4' to delete student\nPress '5' to print object of the task\nPress '6' to save current information into txt\n";

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
