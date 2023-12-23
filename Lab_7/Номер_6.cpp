#include <iostream> // 7, 23, 197
#include <string>

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

				std::cout << "Do you know what integer is?\n ";
				break;
			}
		}
	} while (input);

	for (int i = 0; i < size; i++) {
		num += (str[i] - 48) * pow(10, size - i - 1);
	}

	return num;
}

bool IsEven(int num) {	
	bool even = num & 1;

	if (!even) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Can_be_diveded_7(int num) {
	if (num == 7) {
		return 1;
	}
	if (num < 7) {
		return 0;
	}
	
	if (IsEven(num)) {
		return(Can_be_diveded_7(num >> 1));
	}
	return(Can_be_diveded_7((num >> 1) + 4));
}
bool Can_be_diveded_23(int num) {
	if (num == 23) {
		return 1;
	}
	if (num < 23) {
		return 0;
	}
	
	if (IsEven(num)) {
		return(Can_be_diveded_23(num >> 1));
	}	
	return(Can_be_diveded_23((num >> 1) + 12));	
}
bool Can_be_diveded_197(int num) {
	if (num == 197) {
		return 1;
	}
	if (num < 197) {
		return 0;
	}
		
	if (IsEven(num)) {
		return(Can_be_diveded_197(num >> 1));
	}
	return(Can_be_diveded_197((num >> 1) + 99));
}

int main() {
	int num;
	num = Input_check();

	Can_be_diveded_7(num) ? std::cout << "This can be diveded by 7\n" : std::cout << "This can't be diveded by 7\n";
	Can_be_diveded_23(num) ? std::cout << "This can be diveded by 23\n" : std::cout << "This can't be diveded by 23\n";
	Can_be_diveded_197(num) ? std::cout << "This can be diveded by 197\n" : std::cout << "This can't be diveded by 197\n";

	return 0;
}