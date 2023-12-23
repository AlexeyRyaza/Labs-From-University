#include <iostream>
#include <string>

long long factorial(long long a) {

	long long fac = 1;

	for (int i = 1; i <= a; i++) {

		fac *= i;

	}


	return fac;
}


int main() {

	std::string str;
	getline(std::cin, str);

	long long size = str.size();
	long long answer = factorial(size);

	for (int i = 0; i < 26; ++i) {

		int counter = 0;

		for (int j = 0; j < size; ++j) {

			if ((str[j] == (char)(i + 65)) || (str[j] == (char)(i + 97))) {

				++counter;

			}
		}
		counter = factorial(counter);
		answer /= counter;
	}

	
	std::cout << answer;


	return 0;
}