#include <iostream>
#include <cmath>

int Input_check() {

    bool input = false;
    std::string str;
    int num = 0;
    int length = 0;
    do {

        std::cin >> str;

        length = 0;
        while (str[length] != '\0') {

            length++;

        }


        input = false;
        for (int i = 0; i < length; i++) {

            if ((int)str[i] < 48 || (int)str[i] > 57) {
                input = true;

                std::cout << "TRY HARDER: ";

                break;
            }
        }


    } while (input);


    for (int i = 0; i < length; i++) {

        num += (str[i] - 48) * pow(10, length - i - 1);

    }


    return num;
}
int Input_check_n(int number, int bot = 0, int top = 10) {  // change type
    bool input = true;

    do {

        std::cout << "Enter n: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n') || number < bot || number > top) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}
int Input_check_X(int number, int i, int bot = INT_MIN, int top = INT_MAX) {  // change type
    bool input = true;

    do {

        std::cout << "Enter element[" << i << "]: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n') || number < bot || number > top) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}

int sum(int a, int b) {
	return a + b;
}

double* alloc_mem(int n) {
    double* array = new double[n];

	return array;
}
double fullfil_X(double* X, int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        X[i] = Input_check_X(num, i);
    }

    return *X;
}
double create_Y(double *Y, int n) {
    
    for (int i =0; i < n; i++) {
        Y[i] = 0.1 * tanl(0.1 * (i + 1));
    }

    return *Y;
}

double multiplication(double* X, double* Y, double* C, int n) {

    for (int i = 0; i < n; i++) {
        C[i] = X[i] * Y[i];
    }

    return *C;
}

void print_mass(double *X, int n) {
    for(int i = 0; i < n; i++) {
        std::cout << X[i] << " ";
    }
}

void delete_mass(double* array) {

    delete[] array;
    array = nullptr;

}







