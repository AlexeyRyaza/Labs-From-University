#include <iostream>
#include <fstream>

#include "Functions_2.h"
#include "Struct_2.h"

int size = 0;

void WriteData(const Student* student) {
	std::ofstream fout;
	const std::string path = "myfile.txt";
	fout.open(path);
	
	for (int num = 0; num < size; ++num) {
		fout << "Name: " << student[num].name << "\n";
		fout << "Surname: " << student[num].surname << "\n";
		fout << "Lastname: " << student[num].lastname << "\n";
		fout << "Adress: " << student[num].adress << "\n";
		fout << "Mark for language: " << student[num].mark_1 << "\n";
		fout << "Mark for math: " << student[num].mark_2 << "\n";
		fout << "Mark for physics: " << student[num].mark_3 << "\n\n";
	}

	fout.close();
}

void SetName(Student* student, int num) {
	std::string str_1, str_2, str_3;
	std::cout << "Name of the student: ";
	std::cin >> str_1;
	std::cout << "Surame of the student: ";
	std::cin >> str_2;
	std::cout << "Lastname of the student: ";
	std::cin >> str_3;

	student[num].name = str_1;
	student[num].surname = str_2;
	student[num].lastname = str_3;
}

void SetAdress(Student* student, int num) {
	std::string str;
	std::cout << "Adress of the student: ";
	std::cin >> str;

	student[num].adress = str;
}

void SetMarkLanguage(Student* student, int num) {
	int mark;
	std::cout << "Enter mark for language: ";
	std::cin >> mark;

	student[num].mark_1 = mark;
}

void SetMarkMath(Student* student, int num) {
	int mark;
	std::cout << "Enter mark for Mathematics: ";
	std::cin >> mark;

	student[num].mark_2 = mark;
}

void SetMarkPhysics(Student* student, int num) {
	int mark;
	std::cout << "Enter mark for Physics: ";
	std::cin >> mark;

	student[num].mark_3 = mark;
}

void SetInfo(Student* student, int num) {
	SetName(student, size - 1);
	SetAdress(student, size - 1);
	SetMarkLanguage(student, size - 1);
	SetMarkMath(student, size - 1);
	SetMarkPhysics(student, size - 1);
}

void PrintInfo(const Student* student, int i) {
	std::cout << "\nStudent's information:\n" <<
		"Name: " << student[i].name << "\n" <<
		"Surname: " << student[i].surname << "\n" <<
		"Lastame: " << student[i].lastname << "\n" <<
		"Adrees: " << student[i].adress << "\n" <<
		"Mark for Language: " << student[i].mark_1 << "\n" <<
		"Mark for Math: " << student[i].mark_2 << "\n" <<
		"Mark for Physics: " << student[i].mark_3 << "\n";
}

void AddStudent(Student* list) {
	size += 1;
	SetInfo(list, size - 1);
}

void PrintAllInfo(const Student* list) {
	for (int i = 0; i < size; ++i) {
		PrintInfo(list, i);
	}
}

void DeleteStudent(Student* student, int num) {
	student[num - 1] = student[size - 1];

	--size;
}

void Task(const Student* student) {
	int counter = 0, average = 0;

	std::cout << "\nStudents with average mark higher then 4.5:\n";
	for (int i = 0; i < size; ++i) {
		if (student[i].adress == "minsk" || student[i].adress == "Minsk") {
			average = double(student[i].mark_1 + student[i].mark_2 + student[i].mark_3) / 3;

			if (average >= 4.5) {
				++counter;

				std::cout << student[i].surname << "\n";
			}
		}
	}

	std::cout << "Total amount of such students: " << counter << "\n";
}

void Menu(Student* list, int desicion) {
	int choice = 0;

	switch (desicion) {
	case 0:
		break;
	case 1:
		AddStudent(list);
		break;
	case 2:
		int num, parametr;
		if (size == 0) {
			std::cout << "\nAdd student first\n";
			break;
		}

		std::cout << "Enter number of student: ";
		std::cin >> num;
		while (num <= 0 || num > size) {
			std::cout << "There is no such student\n";
			std::cin >> num;
		}

		std::cout << "Choose what do you want to change:\n1 - Name\n2 - Adress\n3 - Mark for Language\n4 - Mark for Mathematics\n5 - Mark for Physics\n";
		std::cin >> parametr;
		while (parametr < 1 || parametr > 5) {
			std::cout << "There is no such option\n";
			std::cin >> parametr;
		}
		switch (parametr) {
		case 1:
			SetName(list, num - 1);
			break;
		case 2:
			SetAdress(list, num - 1);
			break;
		case 3:
			SetMarkLanguage(list, num - 1);
			break;
		case 4:
			SetMarkMath(list, num - 1);
			break;
		case 5:
			SetMarkPhysics(list, num - 1);
			break;
		default:
			break;
		}
		break;
	case 3:
		PrintAllInfo(list);
		break;
	case 4:
		std::cout << "Enter number of student: ";
		std::cin >> num;
		while (num <= 0 || num > size) {
			std::cout << "There is no such student\n";
			std::cin >> num;
		}
		DeleteStudent(list, num);
		break;
	case 5:
		Task(list);
		break;
	case 6:
		WriteData(list);
		break;
	default:
		break;
	}
}
