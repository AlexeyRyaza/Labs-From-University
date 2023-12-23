#pragma once
#include <fstream>
#include <iostream>

#include "Class_3.h"
#include "Functions_3.h"

int size = 0, average = 0;
const std::string path = "myfile.txt";
std::ofstream fout;

void WriteData(const Student* list, int i) {
	fout.open(path);

	fout.write((char*)&list[i], sizeof(Student));

	fout.close();
}

void EditData(Student* list, int num) {
	fout.open(path, std::ios::app);
	
	Student temp;
	std::cout << "Enter new information\n";

	temp.GetInfo();
	list[num] = temp;

	fout.seekp(sizeof(Student) * num, std::ios::beg);
	fout.write((char*)&temp, sizeof(Student));

	fout.close();
}

void Menu(Student* list, int choice) {
	switch (choice) {
	case 0:
		break;
	case 1:
		AddStudent(list);
		break;
	case 2:
		int num;

		if (size == 0) {
			std::cout << "Add student first";
			break;
		}
		std::cout << "Enter number of student you want to change: ";
		std::cin >> num;
		while (num <= 0 || num > size) {
			std::cout << "There is no such student\n";
			std::cin >> num;
		}
		EditData(list, num - 1);
		break;
	case 3:
		PrintAllInfo(list);
		break;
	case 4:
		int number;

		std::cout << "Enter number of student: ";
		std::cin >> number;
		while (number <= 0 || number > size) {
			std::cout << "There is no such student\n";
			std::cin >> number;
		}

		list[number - 1].PrintInfo();
		break;
	case 5:
		average = AverageMark(list);
		std::cout << "\nAverage mark is: " << average << "\n";
		break;
	case 6:
		average = AverageMark(list);
		QuickSort(list, 0, size);
		PrintAllInfo(list);

		break;
	default:
		std::cout << "You broke everything(";
		break;
	}
}

void AddStudent(Student* list) {
	size += 1;
	list[size - 1].GetInfo();

	WriteData(list, size - 1);
}

void PrintAllInfo(Student* list) {
	for (int i = 0; i < size; ++i) {
		list[i].PrintInfo();
	}
}

void QuickSort(Student* list, int left, int right) {
	if (left >= right) {
		return;
	}
	int key = (left + right) / 2, counter = 0, l, r;
	
	Student* temp = new Student[right - left + 1];
	
	for (int i = left; i <= right; i++) {
		if (list[i].average_mark > list[key].average_mark) {
			temp[counter] = list[i];
			counter++;
		}
	}
	l = counter - 1 + left;
	
	for (int i = left; i <= right; i++) {
		if (list[i].average_mark == list[key].average_mark) {
			temp[counter] = list[i];
			counter++;
		}
	}
	r = counter + left;
	for (int i = left; i <= right; i++) {
		if (list[i].average_mark < list[key].average_mark) {
			temp[counter] = list[i];
			counter++;
		}
	}
	for (int i = left; i <= right; i++) {
		list[i] = temp[i - left];
	}
	
	delete[] temp;
	QuickSort(list, left, l);
	QuickSort(list, r, right);
}

int AverageMark(Student* list) {
	double sum = 0;
	int amount = 0;

	for (int i = 0; i < size; ++i) {
		if ((list[i].adress == "Minsk") || (list[i].adress == "minsk")) {
			++amount;
		}
	}
	for (int i = 0; i < size; ++i) {
		if (list[i].adress == "Minsk" || list[i].adress == "minsk") {
			sum += double(list[i].mark_1 + list[i].mark_2 + list[i].mark_3) / (3 * amount);
			list[i].average_mark = double(list[i].mark_1 + list[i].mark_2 + list[i].mark_3) / 3;
		}
	}

	return sum;
}