#include <iostream>
#include "Functions_1.h"
#include "Struct_1.h"

int size = 0;

void SetName(Worker* worker, int num) {
	char* a = (char*)calloc(100 * sizeof(char), sizeof(char));
	char* b = (char*)calloc(100 * sizeof(char), sizeof(char));
	char* c = (char*)calloc(100 * sizeof(char), sizeof(char));

	printf("Enter name: ");
	scanf("%s", a);
	printf("Enter surname: ");
	scanf("%s", b);
	printf("Enter lastname: ");
	scanf("%s", c);

	worker[num].name = a;
	worker[num].surname = b;
	worker[num].lastname = c;
}

void SetNumber(Worker* worker, int num) {
	printf("Enter tabel number: ");
	int a = 0;
	scanf("%d", &a);
	worker[num].number = a;
}

void SetHours(Worker* worker, int num) {
	printf("Enter hours: ");
	int a = 0;
	scanf("%d", &a);
	worker[num].hours = a;
	worker[num].total_payment = worker[num].hours * worker[num].payment_per_hour;
}

void SetPayment(Worker* worker, int num) {
	printf("Enter payment for hour: ");
	int a = 0;
	scanf("%d", &a);
	worker[num].payment_per_hour = a;
	worker[num].total_payment = worker[num].hours * worker[num].payment_per_hour;
}

void SetInfo(Worker* worker, int num) {
	SetName(worker, num);
	SetNumber(worker, num);
	SetHours(worker, num);
	SetPayment(worker, num);
	worker[num].total_payment = worker[num].hours * worker[num].payment_per_hour;
}

void PrintInfo(const Worker* worker) {
	printf("\nAll information:\n");

	for (int i = 0; i < size; ++i) {
		printf_s("\nName: %s\nSurname: %s\nLastname: %s\nNumber: %d\nHours: %d\nPayment per hour: %lf\nTotal Payment: %lf\n", worker[i].name, worker[i].surname, worker[i].lastname, worker[i].number, worker[i].hours, worker[i].payment_per_hour, worker[i].total_payment);
	}
}

void BubbleSort(Worker* worker) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (worker[i].total_payment < worker[j].total_payment) {
				std::swap(worker[i], worker[j]);
			}
		}
	}
}

void AddWorker(Worker* worker) {
	size += 1;

	SetInfo(worker, size - 1);
}

void AddWorkerEmpty(Worker* worker) {
	size += 1;
}

void DeleteWorker(Worker* worker, int num) {
	worker[num - 1] = worker[size - 1];

	--size;
}

void Menu(Worker* worker, int desicion) {
	int num = 0, parametr = 0;

	switch (desicion) {
	case 0:
		break;
	case 1:
		if (size > 0) {
			AddWorkerEmpty(worker);
			worker[size - 1] = worker[size - 2];
		}
		else {
			printf("Nowhere to copy from");
		}
		break;
	case 2:
		AddWorker(worker);
		break;
	case 3:
		PrintInfo(worker);
		break;
	case 4:
		if (size == 0) {
			printf("\nAdd worker first\n");
			break;
		}
		printf("Enter number of worker: ");
		scanf("%d", &num);
		while (num <= 0 || num > size) {
			printf("There is no such worker\n");
			scanf("%d", &num);
		}

		printf("Choose what do you want to change:\n1 - Name\n2 - Number\n3 - Hours\n4 - Payment for hour\n");
		scanf("%d", &parametr);
		while (parametr < 1 || parametr > 4) {
			printf("There is no such option\n");
			scanf("%d", &parametr);
		}
		switch (parametr)
		{
		case 1:
			SetName(worker, num - 1);
			break;
		case 2:
			SetNumber(worker, num - 1);
			break;
		case 3:
			SetHours(worker, num - 1);
			break;
		case 4:
			SetPayment(worker, num - 1);
			break;
		default:
			break;
		}
		break;
	case 5:
		if (size == 0) {
			printf("\nAdd worker first\n");
			break;
		}
		printf("Enter number of worker: ");
		scanf("%d", &num);
		while (num <= 0 || num > size) {
			printf("There is no such worker\n");
			scanf("%d", &num);
		}
		DeleteWorker(worker, num);
		break;
	case 6:
		BubbleSort(worker);
		PrintInfo(worker);
		break;
	default:
		break;
	}
}