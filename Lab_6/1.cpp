#include <iostream>
#include <string.h>


int main() {

	std::cout << "N: 1\nTask: Find substring of integer in string of diffrent symbols\n";

	char* str;
	char s;
	int length = 0;

	str = (char*)malloc(2);

	std::cout << "write any string: ";
	while ((s = getchar()) != '\n') {
			
		str[length] = s;
		++length;
		str = (char*)realloc(str, 2 + length);
	}
	str[length] = '\0';

	char* num = NULL;
	num = (char*)realloc(num, 1);

	int size = (int)strlen(str), counter = 0;
	bool check = false;
	for (int i = 0; i < size; ++i) {

		check = isdigit(str[i]);
		if (check) {
			++counter;
			num = (char*)realloc(num, 2);
			num[0] = str[i];

			check = false;
			for (int j = i + 1; j < size; j++) {


				check = isdigit(str[j]);
				if (check) {

					++counter;

					num = (char*)realloc(num, 1 + counter);
					num[counter - 1] = str[j];
				}
				else {
					break;
				}
			}
			break;
		}
	}

	num[counter] = '\0';

	std::cout << num;

	std::cout << str;

	free(str);
	free(num);

	return 0;
}