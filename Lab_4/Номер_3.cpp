#include <iostream>


auto Input_check_N(int number) {  // change type
    bool input = true;

    do {

        std::cout << "Set number of rows: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}
auto Input_check_M(int number) {  // change type
    bool input = true;

    do {

        std::cout << "Set number of columns: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}
auto Input_check_num(int number, int i, int j) {  // change type
    bool input = true;

    do {

        std::cout << "Enter element [" << i << "][" << j << "]:"; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}


bool input = true;


int main() {
    
    setlocale(LC_ALL, "Russian");
    std::cout << "№ 3 \nВариант: 6 \nЗадание: Напечатать индексы элементов которые наименьшие в своем столбце и наибольшие в своей строке(или наоборот) \n";


    do {
        int N = 0, M = 0, num = 0, j = 0;
        
        
        N = Input_check_N(N);
        M = Input_check_M(M);
        
        int** a = new int* [N];
        for (int i = 0; i < N; i++) { // allocate memory and fullfil
            a[i] = new int[M];
            j = 0;
            for (int* p = a[i]; p != a[i] + N; p++, j++) {
                *p = Input_check_num(num, i, j);
            }
        }

        for (int i = 0; i < N; i++) { // cout matrix
            for (int* p = a[i]; p != a[i] + N; p++) {
                std::cout << *p << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        int* min_N = new int[N];
        int* max_N = new int[N];
        int* min_M = new int[M];
        int* max_M = new int[M];

        for (int i = 0; i < N; i++) {
            min_N[i] = INT_MAX;
            max_N[i] = INT_MIN;
        }
        for (int i = 0; i < M; i++) {
            min_M[i] = INT_MAX;
            max_M[i] = INT_MIN;
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (a[i][j] < min_M[j]) {
                    min_M[j] = a[i][j];

                }
                if (a[i][j] > max_M[j]) {
                    max_M[j] = a[i][j];
                }


                if (a[i][j] < min_N[i]) {
                    min_N[i] = a[i][j];
                }
                if (a[i][j] > max_N[i]) {
                    max_N[i] = a[i][j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if ((a[i][j] == min_N[i] && a[i][j] == max_M[j]) || (a[i][j] == max_N[i] && a[i][j] == min_M[j])) {
                    std::cout << "indexes are: i = " << i << " j = " << j << "\n";
                }
            }
        }


        for (int i = 0; i < N; i++) {
            delete[] a[i];
            a[i] = nullptr;
        }

        delete[] a;
        a = nullptr;

        std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
        std::cin >> input;

    } while (input);
    
     
}

