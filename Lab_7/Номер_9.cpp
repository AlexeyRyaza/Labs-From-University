#include <iostream>
#include <string>

int Input_check_() {
	bool input = false;
	std::string str;
	double num = 0;
	long long size;

	do {	
		std::cin >> str;

		size = str.size();

		input = false;
		for (int i = 0; i < size; i++) {
			if ((int)str[i] < 48 || (int)str[i] > 57) {
				input = true;

				std::cout << "Do you know what integer is?\n";
				break;
			}
		}
	} while (input);

	for (int i = 0; i < size; i++) {
		num += (str[i] - 48) * pow(10, size - i - 1);
	}

	return num;
}
int Input_check() {
	bool input = false;
	std::string str;
	double num = 0;
	long long size;

	do {

		std::cout << "Input integer number: ";
		std::cin >> str;

		size = str.size();

		input = false;
		for (int i = 0; i < size; i++) {
			if ((int)str[i] < 48 || (int)str[i] > 57) {
				input = true;

				std::cout << "Do you know what integer is?\n";
				break;
			}
		}
	} while (input);

	for (int i = 0; i < size; i++) {
		num += (str[i] - 48) * pow(10, size - i - 1);
	}

	return num;
}
int* exchange_to_3(int* num, int index) {
	for (int i = 0; i < 5; ++i) {
		num[i] = 0;
	}

	for (int i = 4; i >= 0; --i) {
		num[i] = index % 3;

		index /= 3;
	}

	return num;
}
void Back_to_dex(int* answer) {
	int num = 0;
	
	for (int i = 0; i < 5; ++i) {
		num += answer[i] * pow(3, 4 - i);
	}

	std::cout << num;
}
int* Fullfil_with_zeros(int* answer) {
	for (int i = 0; i < 5; ++i) {
		answer[i] = 0;
	}

	return answer;
}

void FirstDay(int* barrel, int** slave) {
	for (int i = 1; i <= 240; ++i) {
		barrel = exchange_to_3(barrel, i);
	
		for (int k = 0; k < 5; ++k) {
			if (barrel[k] == 1) {
				slave[k][i- 1] = 1;
			}
		}
	}


	std::cout << "During the first day:\n";
	for (int i = 0; i < 5; ++i) {
		std::cout << "Slave " << i + 1 << " drank from barrels:\n";
		
		for (int j = 0; j < 240; ++j) {
			if (slave[i][j] == 1) {
				std::cout << j + 1 << " ";
			}
		}
		
		std::cout << "\n";
	}
}
void SecondDay(int* barrel, int** slave, int* result) {
	for (int i = 1; i <= 240; ++i) {
		barrel = exchange_to_3(barrel, i);

		for (int k = 0; k < 5; ++k) {
			if (barrel[k] == 2) {
				slave[k][i - 1] = 2;
			}
		}
	}


	std::cout << "During the second day:\n";
	for (int i = 0; i < 5; ++i) {
		if (result[i] != 1) {
			std::cout << "Slave " << i + 1 << " drank from barrels:\n";

			for (int j = 0; j < 240; ++j) {
				if (slave[i][j] == 2) {
					std::cout << j + 1 << " ";
				}
			}

			std::cout << "\n";
		}
	}
}


int main() {
	
	int* barrel = new int[5];
	int* result = new int[5];
	result = Fullfil_with_zeros(result);

	int** slave = new int* [5];
	for (int i = 0; i < 5; ++i) {
		slave[i] = new int[240];
	}

	FirstDay(barrel, slave);

	int amount, num;
	std::cout << "\n\nEnter amount of slaves who died after the first day and than enter their's numbers: ";
	amount = Input_check_();
	for (int i = 0; i < amount; ++i) {
		num = Input_check_();

		result[num - 1] = 1;
	}

	SecondDay(barrel, slave, result);

	std::cout << "\n\nEnter amount of slaves who died after the second day and than enter their's numbers: ";
	amount = Input_check_();
	for (int i = 0; i < amount; ++i) {
		num = Input_check_();

		result[num - 1] = 2;
	}

	std::cout << "Number of poisoned barrel: ";
	Back_to_dex(result);

	

	for (int i = 0; i < 5; ++i) {
		delete[] slave[i];
		slave[i] = nullptr;
	}
	delete[] slave;
	slave = nullptr;

	return 0;
}