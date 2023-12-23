// task: 1.6
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "Struct_1.h"
#include "Functions_1.h"

int main() {
	Worker* worker = new Worker[100];
	int desicion = 0;

	do {
		printf_s("\nWhat would you like to do:\nPress '0' to exit\nPress '1' to create the copy of the privious one\nPress '2' to add new worker\nPress '3' to print all information\nPress '4' to change some information\nPress '5' to delete some worker\nPress '6' to sort according to payment\n");

		scanf("%d", &desicion);
		while (desicion < 0 || desicion > 6) {
			printf_s("There is no such action\n");
			scanf("%d", &desicion);
		}

		Menu(worker, desicion);

	} while (desicion);

	delete[] worker;
	return 0;
}