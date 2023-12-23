#include <iostream>
#include <string>


int main() {

	bool palindrom = true;
	std::string str, _str;
	getline(std::cin, str);
	_str = str;

	int size = str.size();
	for (int i = 0; i < size; ++i) {

		_str.at(i) = str.at(size - i - 1);
	
	}

	for (int i = 0; i < size / 2; ++i) {

		if (str.at(i) != str.at(size - i - 1)) {

			
			palindrom = false;
			break;
		}
		
	}

	bool check = true;
	for (int i = 0; i < size - 1; ++i) {

		if (str.at(i) != str.at(i + 1)) {
			check = false;
		}

	}
	
	
	if (check) {
		std::cout << "-1";
	}
	else if (palindrom) {

		if (size == 0) {
			std::cout << -1;
		}
		else {
			std::cout << size - 1;
		}

	}
	else {
		std::cout << size;
	}
	
	

	return 0;
}