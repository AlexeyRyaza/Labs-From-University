#include <iostream>

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


int main()
{
    long long n = 0, x, y, counter = 0, counter_ = 0, m;


    n = Input_check(n);


    if (n % 2 == 0) {
        x = n / 2;
        y = n - 1;
    }

    else {
        y = n;
        x = (n - 1) / 2;
    }

    int* a = new int[100];
    int* b = new int[100];
    int* c = new int[100];

    for (int i = 0; i < 100; i++) {
        c[i] = 0;
    }


    while (x > 0) {
        a[counter] = x % 10;
        x /= 10;

        counter++;
    }


    while (y > 0) {

        b[counter_] = y % 10;
        y /= 10;

        counter_++;
    }

    n = counter; m = counter_;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            c[i + j + 1] += (c[i + j] + a[i] * b[j]) / 10;
            c[i + j] = (c[i + j] + a[i] * b[j]) % 10;

        }
    }

    c[1] += (c[0] + 1) / 10;
    c[0] = (c[0] + 1) % 10;
    for (int i = 1; i <= m + n - 2; i++) {
        c[i + 1] += (c[i]) / 10;
        c[i] = (c[i]) % 10;
    }

    counter_ = n + m + 1;
    while (c[counter_] == 0) {
        counter_--;
    }

    std::cout << "Total number of sockets are: ";
    for (int i = counter_; i >= 0; i--) {
        std::cout << c[i];
    }


    delete[] a;
    a = nullptr;

    delete[] b;
    b = nullptr;

    delete[] c;
    c = nullptr;


    return 0;
}