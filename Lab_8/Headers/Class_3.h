#pragma once
#include <iostream>

class Student {
public:
	std::string name, adress;
	int mark_1 = 0, mark_2 = 0, mark_3 = 0;
	double average_mark = 0;

	void GetName() {
		std::string str;
		std::cout << "Name of the student: ";
		std::cin >> str;

		name = str;
	}

	void GetAdress() {
		std::string str;
		std::cout << "Adress of the student: ";
		std::cin >> str;

		adress = str;
	}

	void GetMarkLanguage() {
		int mark;
		std::cout << "Enter mark for language: ";
		std::cin >> mark;

		mark_1 = mark;
	}

	void GetMarkMath() {
		int mark;
		std::cout << "Enter mark for Mathematics: ";
		std::cin >> mark;

		mark_2 = mark;
	}

	void GetMarkPhysics() {
		int mark;
		std::cout << "Enter mark for Physics: ";
		std::cin >> mark;

		mark_3 = mark;
	}

	void GetInfo() {
		GetName();
		GetAdress();
		GetMarkLanguage();
		GetMarkMath();
		GetMarkPhysics();
	}

	void PrintInfo() {
		std::cout << "\nStudent's information:\n" <<
			"Name: " << name << "\n" <<
			"Adrees: " << adress << "\n" <<
			"Mark for Language: " << mark_1 << "\n" <<
			"Mark for Math: " << mark_2 << "\n" <<
			"Mark for Physics: " << mark_3 << "\n";
	}
};
