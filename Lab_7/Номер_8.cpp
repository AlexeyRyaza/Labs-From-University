#include <iostream>

int number_of_bytes(int num) {
	int i = 0;
	while (num != 0) {
		num /= 3;
		++i;
	}

	return i;
}
int* exchange_to_3(int* num, int index,int size) {
	for (int i = 0; i < size; ++i) {
		num[i] = 0;
	}

	int i = size - 1;
	while(index != 0) {
		num[i] = index % 3;

		index /= 3;
		--i;
	}

	return num;
}
int* translate_to_shit_system(int* ternary,const int size) {
	int balance = 0;
	for (int i = size - 1; i > 0; --i) {
		
		if (ternary[i] == 0) {
			ternary[i] = 3;

			balance = 1;
			while (ternary[i - balance] == 0) {
				ternary[i - balance] = 2;
			
				++balance;
			}
			ternary[i - balance] -= 1;
	
		}
	
	}

	return ternary;
}


int main() {
	long long num;
	std::cin >> num;

	int size = number_of_bytes(num);
	int* ternary = new int[size];
	ternary = exchange_to_3(ternary, num, size);

	ternary = translate_to_shit_system(ternary, size);

	for (int i = 0; i < size; ++i) {
		if (ternary[i] == 0 && i == 0) {
			continue;
		}
		
		std::cout << ternary[i];
	}

	return 0;
}