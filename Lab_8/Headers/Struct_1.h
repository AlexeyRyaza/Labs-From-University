#pragma once
struct Worker {
	char* name = (char*)calloc(100 * sizeof(char), sizeof(char));
	char* surname = (char*)calloc(100 * sizeof(char), sizeof(char));
	char* lastname = (char*)calloc(100 * sizeof(char), sizeof(char));

	int number = 0, hours = 0;
	double payment_per_hour = 0, total_payment = 0;
};
