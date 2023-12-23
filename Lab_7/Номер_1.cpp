#include <iostream>
#include <string>

std::string check_number() {
	std::string num;
	
	while (true) {
		std::cin >> num;
		
		unsigned int size = num.size();
		bool correct_input = true;
		
		for (int i = 0; i < size; ++i) {
			if ((num.at(i) != '0') && (num.at(i) != '1') && (num.at(i) != '-')) {
				correct_input = false;
				break;
			}
		}
		
		if (num.at(0) == '0') {
			std::cout << "0 can't go first\n";
			continue;
			//correct_input = false;
		}

		if ((size == 1) && (num == "-")) {
			correct_input = false;
		}

		if (!correct_input) {
			std::cout << "Please use only 1 and 0\n";
			continue;
		}
		break;
	}

	return num;
}
void main_func(std::string str, int size) {
	if (str.at(0) == '-') {
		std::cout << "1.";
		for (int i = 1; i < size; ++i) {
			std::cout << (str.at(i) == '0' ? '1' : '0');
		}
	}
	else {
		std::cout << "0." << str;
	}
}

int main() {	
	std::cout << "Enter number in binary code: ";
	std::string num;
	num = check_number();

	unsigned int size = num.size();

	main_func(num, size);

	return 0;
}