#include <iostream>

long long** alloc_mem(long long n = 0, long long m = 0) {

    long long** matrix = new long long* [n];

    for (long long i = 0; i < n; i++) {
        matrix[i] = new long long[m];
    }
    return matrix;
}


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

long long Input_check_num(long long number, long long i, long long j) {  // change type
    bool input = true;

    do {

        std::cout << "Enter element[" << i << "][" << j << "]: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}
long long fulfill_matrix(long long n, long long m, long long** matrix) {
    long long num = 0, j;
    for (long long i = 0; i < n; i++) {
        j = 0;
        for (long long* p = matrix[i]; p < matrix[i] + m; p++, j++) {

            *p = Input_check_num(num, i, j);

        }
    }
    return **matrix;
}


long long counter_even(long long n, long long m, long long** matrix) {

    long long cnt = 0;

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {

            if (i == j && (matrix[i][j] % 2 == 0)) {
                cnt++;
            }

        }
    }
    return cnt;
}
long long* crete_mass(long long n, long long m, long long** matrix, long long* array) {

    int lenght = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {

            if (i == j && (matrix[i][j] % 2 == 0)) {
                array[lenght] = matrix[i][j];
                lenght++;
            }

        }
    }

    return array;
}


long long multiplication(long long* array, long long counter) {
    long long mult = 1;
    for (long long i = 0; i < counter; i++) {

        mult *= array[i];

    }

    return mult;
}


long long Input_check_n(long long number, int bot = 1, int top = 10) {  // change type
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
long long Input_check_k(long long number, int bot = 1, int top = 10) {  // change type
    bool input = true;

    do {

        std::cout << "Enter k: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n') || number < bot || number > top) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}


void print_matrix(long long n, long long m, long long** matrix) {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void print_array(long long* array, long long counter) {
    std::cout << "Array: ";
    for (long long i = 0; i < counter; i++) {

        std::cout << array[i] << " ";

    }

    std::cout << "\n";

}

void delete_matrix(long long** matrix, int n) {

    for (int i = 0; i < n; i++) {
        
        delete[] matrix[i];
        matrix[i] = nullptr;

    }

    delete matrix;
    matrix = nullptr;

}
void delete_mass(long long* array) {

    delete[] array;
    array = nullptr;

}

int main() {


    std::cout << "N: 3\nTask: Calculate elements' miltiplication of created dynamic array.\n";


    int input = 1;

    do {

        long long n = 0, k = 0, counter = 0;
        std::cout << "Enter n: ";
        n = Input_check();
        std::cout << "Enter k: ";
        k = Input_check();

        long long** matrix = alloc_mem(n, k);
        **matrix = fulfill_matrix(n, k, matrix);


        counter = counter_even(n, k, matrix);


        long long* array = new long long[counter];
        array = crete_mass(n, k, matrix, array);

        std::cout << "\n";
        print_array(array, counter);


        long long mult = multiplication(array, counter);

        if (mult != 1) {
            std::cout << "\nMultiplication of elements is: " << mult << "\n";
        }
        else {
            std::cout << "\nNo elements in array(";
        }

        delete_mass(array);
        delete_matrix(matrix, n);

        //std::cout << "\n" << counter;
        //print_matrix(n, k, matrix);
        std::cout << "\n";
        std::cout << "If you want to run programm again, please type 1, in the other way type 0\n";
        std::cin >> input;
        if (input != 0) {
            input = 1;
        }


    } while (input);






}