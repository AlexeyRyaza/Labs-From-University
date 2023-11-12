#include <iostream>
#include <algorithm>

auto Input_check(int number, int i, int j) {  // change type
    bool input = true;

    do {

        std::cout << "Enter element [" <<  i << "]["  << j << "]: "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number;
}

bool input = true;

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    std::cout << "№ 2 \nВариант: 6 \nЗадание: Определить количество четных елементов на диагоналях \n";

    do {
        int counter = 0, z = 0;
        const int n = 3;
        const int m = 3;


        int matrix[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = Input_check(z, i, j);
            }
        }

        int n_1 = std::min(n, m);
        int m_1 = n_1;


        for (int i = 0; i < n_1; i++) {
            for (int j = 0; j < m_1; j++) {
                if (((i == j) || (i == m_1 - j - 1)) && (matrix[i][j] % 2 == 0)) {
                    counter += 1;
                    //std::cout << matrix[i][j] << "\n";
                }
            }
        }

        std::cout << "Number of even numbers: " << counter;

    
        std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
        std::cin >> input;


    } while (input);
    
    
    
    return 0;
}