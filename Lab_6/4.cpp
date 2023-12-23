#include <iostream>
#include <string>

std::string refrasing(std::string str) {

	str.find("ce") < 100 ? str.replace(str.find("ce"), 1, "s") : str;
	str.find("ci") < 100 ? str.replace(str.find("ci"), 1, "s") : str;
	str.find("cy") < 100 ? str.replace(str.find("cy"), 1, "s") : str;
	str.find("c") < 100 ? str.replace(str.find("c"), 1, "k") : str;

	str.find("qu") < 100 ? str.replace(str.find("qu"), 2, "kv") : str;
	str.find("q") < 100 ? str.replace(str.find("q"), 1, "k") : str;

	str.find("x") < 100 ? str.replace(str.find("x"), 1, "ks") : str;
	
	str.find("w") < 100 ? str.replace(str.find("w"), 1, "v") : str;

	str.find("ph") < 100 ? str.replace(str.find("ph"), 2, "f") : str;
	str.find("you") < 100 ? str.replace(str.find("you"), 3, "u") : str;
	str.find("oo") < 100 ? str.replace(str.find("oo"), 2, "u") : str;
	str.find("ee") < 100 ? str.replace(str.find("ee"), 2, "i") : str;
	str.find("th") < 100 ? str.replace(str.find("th"), 2, "z") : str;


	// Now we do the same but for upper case
	str.find("Ce") < 100 ? str.replace(str.find("Ce"), 1, "S") : str;
	str.find("Ci") < 100 ? str.replace(str.find("Ci"), 1, "S") : str;
	str.find("Cy") < 100 ? str.replace(str.find("Cy"), 1, "S") : str;
	str.find("C") < 100 ? str.replace(str.find("C"), 1, "K") : str;

	str.find("Qu") < 100 ? str.replace(str.find("Qu"), 2, "Kv") : str;
	str.find("Q") < 100 ? str.replace(str.find("Q"), 1, "K") : str;

	str.find("X") < 100 ? str.replace(str.find("X"), 1, "Ks") : str;

	str.find("W") < 100 ? str.replace(str.find("W"), 1, "V") : str;

	str.find("Ph") < 100 ? str.replace(str.find("Ph"), 2, "F") : str;
	str.find("You") < 100 ? str.replace(str.find("You"), 3, "U") : str;
	str.find("Oo") < 100 ? str.replace(str.find("Oo"), 2, "U") : str;
	str.find("Ee") < 100 ? str.replace(str.find("Ee"), 2, "I") : str;
	str.find("Th") < 100 ? str.replace(str.find("Th"), 2, "Z") : str;
	

	return str;
}

std::string delete_repeats(std::string str) {

		int size = str.size();
		for (int i = 0; i < size - 1; ++i) {

			if ((str.at(i) == str.at(i + 1))) {

				str.erase(i, 1);
				size = str.size();
			}

		}

		

	return str;
}




int main() {
	
	std::string* array = new std::string[100];
	std::string str;

	int counter = 0;
	while (std::getline(std::cin, str)) {

		if (str.empty()) {
			continue;
		}

		array[counter] = str;

		counter++;
	}

	for (int i = 0; i < counter; ++i) {

		array[i] = refrasing(array[i]);

	}

	for (int i = 0; i < counter; i++) {

		str = refrasing(array[i]);

		while (array[i] != str) {

			array[i] = refrasing(array[i]);
			str = refrasing(str);

		}

	}

	for (int i = 0; i < counter; ++i) {

		str = delete_repeats(array[i]);

		while (array[i] != str) {

			array[i] = delete_repeats(array[i]);
			str = delete_repeats(str);

		}

		array[i] = delete_repeats(array[i]);

	}


	for (int i = 0; i < counter; i++) {

		std::cout << array[i] << '\n';

	}

	delete[] array;
	array = nullptr;


	return 0;
}