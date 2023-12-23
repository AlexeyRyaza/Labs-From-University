#include <iostream>
#include <string>

bool is_minus_1 = false, is_minus_2 = false;

int Input_check() {

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

void Sum(std::string& str_1, std::string& str_2, int osn) {
	str_1.insert(0, 1, 0);

	int size_1 = str_1.size() - 1;
	int size_2 = str_2.size() - 1;

	int k;
	for (int i = size_2; i >= 0; --i, --size_1) {
		str_1.at(size_1) = char(str_1.at(size_1) + str_2.at(i));

		k = size_1 - 1;
		if (str_1.at(size_1) >= osn) {

			while (str_1.at(k + 1) >= osn && k > 0) {
				str_1.at(k + 1) = char((int)(str_1.at(k + 1) % osn));
				++str_1.at(k);
				--k;
			}
		}
	}
}

void Minus(std::string& str_1, std::string& str_2, int osn) {
	int size_1 = str_1.size() - 1;
	int size_2 = str_2.size() - 1;

	for (int i = 0; i < size_2 + 1; ++i) {
		if (str_1.at(size_1 - i) < str_2.at(size_2 - i)) {
			str_1.at(size_1 - i - 1)--;
			str_1.at(size_1 - i) = char(str_1.at(size_1 - i) + osn);
		}
		str_1.at(size_1 - i) = char(str_1.at(size_1 - i) - str_2.at(size_2 - i));
	}
}

bool Print(std::string& str_1, std::string& str_2, int osn) {
	int size_1 = str_1.size();
	int size_2 = str_2.size();

	if (is_minus_1 == is_minus_2) {
		if (size_1 < size_2) {
			std::swap(str_1, str_2);
		}

		Sum(str_1, str_2, osn);
		if (is_minus_1) {
			std::cout << '-';
		}
	}
	else {
		if (size_2 > size_1) {
			std::swap(str_1, str_2);

			if (is_minus_2) {
				std::cout << '-';
			}

		}
		else if (size_1 == size_2) {

			if (str_1 < str_2) {
				std::swap(str_1, str_2);
			}

			if (is_minus_2) {
				std::cout << '-';
			}
			else if (str_1 == str_2) {
				std::cout << '0';
				return 0;
			}
			else if (is_minus_1) {
				std::cout << '-';
			}
		}
		else if (is_minus_1) {
			std::cout << '-';
		}

		Minus(str_1, str_2, osn);
	}

	while (str_1.at(0) == 0) {
		str_1.erase(0, 1);
	}

	for (char i : str_1) {
		if (i < 10) {
			std::cout << char(i + '0');
		}
		else {
			std::cout << char(i + 'A' - 10);
		}
	}
}

bool number_check(std::string& str, int osn) {
	for (char& i : str) { // O(n)
		if (i >= '0' && i <= '9') {
			i = char(int(i) - '0');
		}
		else if (i >= 'A' && i <= 'A' - 11 + osn) {
			i = char(int(i) - 'A' + 10);
		}
		else {
			return false;

		}
	}
	return true;
}


int main() {
	std::cout << "Enter notation: ";
	int osn = Input_check();

	std::cout << "Enter first: ";
	std::string str_1;

	do {
		std::cin >> str_1;
	} while (!number_check(str_1, osn));

	std::cout << "Enter second: ";
	std::string str_2;

	do {
		std::cin >> str_2;
	} while (!number_check(str_2, osn));

	if (str_1.at(0) == '-') {
		is_minus_1 = true;
		str_1.erase(0, 1);
	}
	if (str_2.at(0) == '-') {
		is_minus_2 = true;
		str_2.erase(0, 1);
	}

	std::string copy_str_1 = str_1;
	std::string copy_str_2 = str_2;
	std::cout << "Sum: ";
	Print(str_1, str_2, osn);

	std::cout << "\nMinus: ";
	is_minus_2 = !is_minus_2;

	Print(copy_str_1, copy_str_2, osn);
}