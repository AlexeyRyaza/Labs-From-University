#include <iostream>

char* change(int space_1, int space_2, int space_3, char* str) {

	int mx;

	if (space_1 == 0) {
		mx = std::max(space_3 - space_2 - 1, space_2 - space_1);
	}
	else {
		mx = std::max(space_3 - space_2 - 1, space_2 - space_1 - 1);
	}

	for (int i = 0; i < mx; ++i) {
		
		if (space_1 == 0) {
			std::swap(str[i], str[space_3 - i - 1]);
		}
		else {
			std::swap(str[space_1 + i + 1],str[space_3 - i - 1]);

		}
		
	}

	return str;
}


int main() {

	char* str = NULL;
	char s;
	str = (char*)malloc(2);
	int pos[10];
	int counter = 0, cnt = 0;

	std::cout << "Enter your string: ";
	while ((s = getchar()) != '\n') {

		str[counter] = s;
		++counter;

		if (s == ' ') {

			pos[cnt] = counter;
			++cnt;
		}

		str = (char*)realloc(str, 2 + counter);
	}
	str[counter] = '\0';

	if (cnt == 0) {
		std::cout << "Edited string: " << str;
		return 0;
	}

	int space_1 = 0, space_2, space_3, num_replace = (cnt + 1) / 2;

	if (cnt >= 2) {
		space_2 = pos[0] - 1;
		space_3 = pos[1] - 1;
	}
	else {
		space_2 = pos[0] - 1;
		space_3 = strlen(str);
	}
	
	for (int i = 0; i < num_replace; ++i) {

		str = change(space_1, space_2, space_3, str);

		cnt -= 2;
		space_1 = space_3;
		space_2 = pos[i + 2] - 1;
		if (cnt >= 2) {
			space_3 = pos[i + 3] - 1;
		}
		else {
			space_3 = strlen(str);
		}

	}

	std::cout << "Edited string: " << str;

	return 0;
}