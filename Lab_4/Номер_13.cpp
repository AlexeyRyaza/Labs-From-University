#include <iostream>
#include <limits>

auto Input_check(int number) {  // change type
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
    


    do
    {
        int n = 0, x, y, i, j, a, size;
        int** matrix;
        int** submatrix;

        n = Input_check(n);


        matrix = (int**)malloc(n * sizeof(int*));
        for (i = 0; i < n; i++)
        {
            matrix[i] = (int*)calloc(n, sizeof(int));
        }

        size = n * n;
        if (n == 1)
        {
            std::cout << " - " << "\n";
        }
        else if (n == 2)
        {
            std::cout << "It is impossible to build tha magic square\n";
        }
        else if (n % 2 == 1)
        {
            y = 0; x = n / 2;
            matrix[0][n / 2] = 1;
            for (i = 1; i < size; i++){
                if (matrix[abs(n - y - 1) % n][(x + 1) % n] == 0){
                    matrix[abs(n - y - 1) % n][(x + 1) % n] = i + 1;
                    if (y != n - 1){
                        y++;
                    }
                    else{
                        y = 0;
                    }
                    x++;
                }
                else{
                    matrix[abs(n - y + 1) % n][x % n] = i + 1;
                    if (y != 0){
                        y--;
                    }
                    else{
                        y = n - 1;
                    }
                }
            }
        }
        else if ((n / 2) % 2 == 0){
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    matrix[i][j] = i * n + j + 1;
                }
            }


            for (i = 0; i < n / 4; i++){
                for (j = 0; j < n / 2; j++){
                    std::swap(matrix[i][n / 2 - 1 + j], matrix[n - 1 - i][3 * n / 4 - 1 - j]);
                }
            }


            for (i = 0; i < n / 2; ++i){
                for (j = 0; j < n / 4; ++j){
                    std::swap(matrix[n / 4 + i][j], matrix[3 * n / 4 - 1 - i][n - 1 - j]);
                }
            }
        }
        else{
            submatrix = (int**)malloc(n / 2 * sizeof(int*));
            a = (n - 2) / 4;
            for (i = 0; i < n / 2; ++i){
                submatrix[i] = (int*)malloc(n / 2 * sizeof(int));


                for (j = 0; j < n / 2; ++j){
                    if (i <= a){
                        submatrix[i][j] = 1;
                    }
                    else if (i == a + 1){
                        submatrix[i][j] = 2;
                    }
                    else{
                        submatrix[i][j] = 3;
                    }
                }
            }
            std::swap(submatrix[a][n / 4], submatrix[a + 1][n / 4]);


            a = n / 2;
            y = 0; x = a / 2;
            int counter = 1;


            for (i = 0; i < a; i++){
                for (j = 0; j < a; j++){
                    if (submatrix[abs(a - y) % a][x % a] == 1){
                        matrix[2 * (abs(a - y) % a)][2 * (x % a) + 1] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a)] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a) + 1] = counter++;
                        matrix[2 * (abs(a - y) % a)][2 * (x % a)] = counter++;
                    }
                    else if (submatrix[abs(a - y) % a][x % a] == 2) {
                        matrix[2 * (abs(a - y) % a)][2 * (x % a)] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a)] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a) + 1] = counter++;
                        matrix[2 * (abs(a - y) % a)][2 * (x % a) + 1] = counter++;
                    }
                    else{
                        matrix[2 * (abs(a - y) % a)][2 * (x % a)] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a) + 1] = counter++;
                        matrix[2 * (abs(a - y) % a) + 1][2 * (x % a)] = counter++;
                        matrix[2 * (abs(a - y) % a)][2 * (x % a) + 1] = counter++;
                    }


                    if (y != a - 1){
                        y++;
                    }
                    else {
                        y = 0;
                    }
                    x++;
                }
                if (y != 0){
                    y--;
                }
                else{
                    y = a - 1;
                }
                if (y != 0){
                    y--;
                }
                else{
                    y = a - 1;
                }
                x--;
            }


            for (i = 0; i < n / 2; i++){
                free(submatrix[i]);
            }
            free(submatrix);
        }


        if (n > 2){
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    std::cout << matrix[i][j] << '\t';
                }
                std::cout << '\n';
            }
        }

        for (i = 0; i < n; i++){
            free(matrix[i]);
            matrix[i] = NULL;
        }
        //free(matrix);
        //matrix = nullptr;


        std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
        std::cin >> input;
        if (input != 0) {
            input = 1;
        }
    } while (input);

    return 0;
}