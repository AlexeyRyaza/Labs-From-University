#include <iostream>
#include <string.h>


int main() {
	 
	char* str = NULL;
	char s;
	str = (char*)malloc(2);
	int counter = 0;

	std::cout << "Enter your string: ";
	while ((s = getchar()) != '\n') {

		str[counter] = s;
		++counter;

		str = (char*)realloc(str, 2 + counter);
	}

	str[counter] = '\0';

	std::cout << "\nWhich symbol do you want to delete?\n";
	char ch;
	std::cin >> ch;
	int total = 0, check = 0;

	//std::cout << "counter: " << counter << '\n';


	for (int i = 0; i < counter - total; ++i) {

		if (ch == str[i]) {

			total++;

			for (int j = i; j < counter - 1; ++j) {

				std::swap(str[j], str[j + 1]);

			}

			--i;

		}


	}


	//std::cout << "\n" << total;


	if (total == 0) {
		std::cout << "there is no such symbol(";
	}
	else {

		std::cout << "Result: ";
		for (int i = 0; i < counter - total; ++i) {

			std::cout << str[i];

		}


	}

	
	
	return 0;
}