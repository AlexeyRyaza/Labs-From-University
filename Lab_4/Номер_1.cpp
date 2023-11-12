#include <iostream>
#include <cmath>


auto Input_check(int number, int i) {  // change type
    bool input = true;

    do {

        std::cout << "Enter x" << i << ": "; // Change x
        std::cin >> number;


        if ((std::cin.fail()) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else input = false;


    } while (input);

    return number; // change
}
auto Input_check_n(int number) {  // change type
    bool input = true;

    do {

        std::cout << "Enter n: "; // Change x
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


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "№ 1 \nВариант: 6 \nЗадание: Сдвинуть элементы массива на n позиций влево \n";
    
    do {
        const int k = 10;
        int array[k], b[k];
        int x = 0, n = 0;

        for (int i = 0; i < k; i++)
        {
            array[i] = Input_check(x, i);
            b[i] = array[i];
        }

        n = Input_check_n(n);

        n %= k;

        for (int i = 0; i < k; i++)
        {
            if (k - n > i) {
                array[i] = b[i + n];

            }
            else {
                array[i] = b[abs(k - i - n)];
            }
        }

        for (int i = 0; i < k; i++)
        {
            std::cout << array[i] << " ";

        }

        std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
        std::cin >> input;
        if (input != 0) {
            input = true;
        }

    } while (input);
    
   
}