#include <iostream>
#include <string>

int Length(long long num) {
	int counter = 0;
	while (num != 0) {
		counter++;
		num /= 10;
	}

	return counter;
}
int* fullfil(int length, int num) {
	int* digits = new int[length];
	while (length != -1) {
		digits[length - 1] = num % 10;

		length -= 1;
		num /= 10;
	}

	return digits;
}
void Cout_1000(int digit, std::string& answer) {
	for (int i = 0; i < digit; ++i) {
		answer.push_back('M');
	}
}
void Cout_100(int digit, std::string& answer) {

	if (digit <= 3) {
		for (int i = 0; i < digit; ++i) {
			answer.push_back('C');
		}
	}
	if (digit == 4) {
		answer.push_back('C');
		answer.push_back('D');
	}
	if (digit == 5) {
		answer.push_back('D');
	}
	if (digit >= 6 && digit <= 8) {
		answer.push_back('D');
		for (int i = 0; i < digit - 5; ++i) {
			answer.push_back('C');
		}
	}
	if (digit == 9) {
		answer.push_back('C');
		answer.push_back('M');

	}

}
void Cout_10(int digit, std::string& answer) {

	if (digit <= 3) {
		for (int i = 0; i < digit; ++i) {
			answer.push_back('X');
		}
	}
	if (digit == 4) {
		answer.push_back('X');
		answer.push_back('L');
	}
	if (digit == 5) {
		answer.push_back('L');
	}
	if (digit >= 6 && digit <= 8) {
		answer.push_back('L');
		for (int i = 0; i < digit - 5; ++i) {
			answer.push_back('X');
		}
	}
	if (digit == 9) {
		answer.push_back('X');
		answer.push_back('C');
	}
}
void Cout_1(int digit, std::string& answer) {
	if (digit <= 3) {
		for (int i = 0; i < digit; ++i) {
			answer.push_back('I');
		}
	}
	if (digit == 4) {
		answer.push_back('I');
		answer.push_back('V');
	}
	if (digit == 5) {
		answer.push_back('V');
	}
	if (digit >= 6 && digit <= 8) {
		answer.push_back('V');
		for (int i = 0; i < digit - 5; ++i) {
			answer.push_back('I');
		}
	}
	if (digit == 9) {
		answer.push_back('I');
		answer.push_back('X');
	}

}

int main() {
	std::string answer;
	long long num;
	std::cin >> num;

	int length = Length(num);

	int* digits = new int[length];
	digits = fullfil(length, num);

	int place_number = length;
	for (int i = 0; i < length; ++i, --place_number) {
		if (place_number == 4) {
			Cout_1000(digits[i], answer);
		}
		if (place_number == 3) {
			Cout_100(digits[i], answer);
		}
		if (place_number == 2) {
			Cout_10(digits[i], answer);
		}
		if (place_number == 1) {
			Cout_1(digits[i], answer);
		}
	}

	std::cout << answer;

	delete[] digits;
}