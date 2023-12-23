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

int Size(const std::string str) {

	unsigned int size;
	if (str.at(0) == '-') {
		size = str.size() - 1;
	}
	else {
		size = str.size();
	}

	return size;
}
void Delete_minus(std::string& str) {
	if (str.at(0) == '-') {
		str.erase(0, 1);
	}
}
bool Is_negative(const std::string str) {
	bool is_negative = false;

	if (str.at(0) == '-') {
		is_negative = true;
	}

	return is_negative;
}

int* Plus_one(int* num, int size) {
	num[size] += 1;

	for (int i = size; i >= 0; --i) {
		if (num[i] > 1) {
			num[i - 1] += 1;
			num[i] -= 1;
		}
	}

	return num;
}
int* Fulfill_with_zeros(int* num, int size) {
	for (int i = 1; i < size; ++i) {
		num[i] = 0;
	}

	return num;
}
int* Fulfill(int* num, std::string str, int size) {
	if (num[0] == 0) {
		for (int i = 0; i < size; ++i) {
			str.at(i) == '0' ? num[i + 1] = 0 : num[i + 1] = 1;
		}
	}
	else {
		for (int i = 0; i < size; ++i) {
			str.at(i) == '0' ? num[i + 1] = 1 : num[i + 1] = 0;
		}
		num = Plus_one(num, size);
	}

	return num;
}
int* Fulfill(int* num, std::string str, int size, int diffrence) {
	int counter_for_str = 0;
	if (num[0] == 0) {
		for (int i = diffrence; i <= size; ++i) {
			str.at(counter_for_str) == '0' ? num[i] = 0 : num[i] = 1;
		}
	}
	else {
		for (int i = diffrence; i <= size; ++i) {
			str.at(counter_for_str) == '0' ? num[i] = 1 : num[i] = 0;
		}
		num = Plus_one(num, size);
	}

	return num;
}

int* Sum(int* num_1, int* num_2, int max_size) {
	int* answer = new int[max_size];

	for (int i = max_size - 1; i >= 0; --i) {
		answer[i] = num_1[i] + num_2[i];
	}

	for (int i = max_size - 1; i >= 0; --i) {
		if (answer[i] > 1) {
			answer[i - 1] += 1;
			answer[i] -= 2;
		}
	}

	return answer;
}

void Print(int* num, int size) {
	if (num[0] == 1) {
		std::cout << "-";
		
		for (int i = 1; i <= size; ++i) {
			num[i] == 0 ? std::cout << '1' : std::cout << '0';
		}
	}
	else {
		for (int i = 1; i <= size; ++i) {
			num[i] == 0 ? std::cout << '0' : std::cout << '1';
		}
	}
}

int main() {
	std::string str_1, str_2;
	
	std::cout << "Enter first number: ";
	str_1 = check_number();
	int size_1 = Size(str_1);

	std::cout << "Enter second number: ";
	str_2 = check_number();
	int size_2 = Size(str_2);
	
	bool is_negative_1 = Is_negative(str_1), is_negative_2 = Is_negative(str_2);

	int max_size = std::max(size_1, size_2);
	int diffrence = abs(size_1 - size_2);

	Delete_minus(str_1);
	Delete_minus(str_2);

	int* num_1 = new int[max_size + 1];
	int* num_2 = new int[max_size + 1];

	if (is_negative_1) {
		num_1[0] = 1;
	}
	else {
		num_1[0] = 0;
	}

	if (is_negative_2) {
		num_2[0] = 1;
	}
	else {
		num_2[0] = 0;
	}
	// Always enter size + 1 as we made additional cell for "sign bit"

	num_1 = Fulfill_with_zeros(num_1, max_size + 1);
	num_2 = Fulfill_with_zeros(num_2, max_size + 1);

	if (size_1 < size_2) {
		num_1 = Fulfill(num_1, str_1, max_size, diffrence);
		num_2 = Fulfill(num_2, str_2, max_size);
	}
	else if(size_1 > size_2){
		num_1 = Fulfill(num_1, str_1, max_size);
		num_2 = Fulfill(num_2, str_2, max_size, diffrence);
	}
	else {
		num_1 = Fulfill(num_1, str_1, max_size);
		num_2 = Fulfill(num_2, str_2, max_size);
	}

	int* answer = new int[max_size + 1];
	answer = Sum(num_1, num_2, max_size + 1);
	
	Print(answer, max_size);

	delete[] answer;
	delete[] num_1;
	delete[] num_2;

	return 0;
}