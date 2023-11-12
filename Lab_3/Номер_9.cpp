#include <iostream>

auto Input_check_n(int n) {  // change type
    bool input = true;

    do {

        std::cout << "Enter n: "; // Change x
        std::cin >> n;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return n;
}
auto Input_check_a(int a, int i) {  // change type
    bool input = true;

    do {

        std::cout << "Set a" << i << ": "; // Change x
        std::cin >> a;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return a;
}



int main() {
	int n = 0, a = 0, sum = 0;

    n = Input_check_n(n);

    for (int i = 0; i <= n; i++) {
        a = Input_check_a(a, i);

		sum += pow(-2, i) * a;

	}
	std::cout << "The result is: " << sum;

}
