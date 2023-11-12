#include <iostream>
#include <cmath>
#include "Dliba.h"

extern "C" __declspec(dllexport) int Input_check() {

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
 
extern "C" __declspec(dllexport) int Sum(int a, int b) {
	return a + b;
}

extern "C" __declspec(dllexport) int Input_check_n(int number, int bot = 0, int top = INT_MAX) {  // change type
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

extern "C" __declspec(dllexport) void Print_mass(double* X, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << X[i] << " ";
    }
}

extern "C" __declspec(dllexport) double Input_check_num(double number, int i, int bot = INT_MIN, int top = INT_MAX) {  // change type
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

    number = fmod(number, 3.1415);

    return number; // change
}
extern "C" __declspec(dllexport) double Fullfill_B(double* B, int n) {

    double num = 0;

    for (int i = 0; i < n; i++) {

        B[i] = Input_check_num(num, i);

    }

    return *B;
}


extern "C" __declspec(dllexport) double Solution(double* B, int a, int b) { 

    int center = (a + b) / 2;

    if (a != b) {
        return Solution(B, a, center) + Solution(B, center + 1, b);
    }
    else {
        return sin(B[a]) * cos(B[a]);
    }

}

extern "C" __declspec(dllexport) void Delete_mem(double* B) {

    delete[] B;

}