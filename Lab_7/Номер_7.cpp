#include <iostream>

const short n1 = 10001;
const short n2 = 201;
const short n3 = 500;

void per(short** as, short** mas, short num) {
    short sh = 0, pt = 0, am = 0;
    short* arr = new short[n2];
    for (short i = 0; i < n2; i++) {
        if (as[num][i] != 0) {
            pt = i;
            sh = n2 - pt;
            break;
        }
    }
    for (short i = 0; i < sh / 2; i++) {
        arr[i] = as[num][pt + i];
        arr[i + sh / 2] = as[num][pt + i + sh / 2];
    }
    if (sh % 2 == 1) {
        arr[sh - 1] = as[num][pt + sh - 1];
    }

    while (sh != 0) {
        for (short i = 0; i < sh; i++) {
            if (i == sh - 1) {
                mas[num][am] = arr[i] % 2;
                arr[i] = arr[i] / 2;
                am++;

            }
            else
            {
                arr[i + 1] = arr[i + 1] + 10 * (arr[i] % 2);
                arr[i] = arr[i] / 2;
            }
        }

        if (sh != 0) {
            while (arr[0] == 0) {
                for (short i = 0; i < sh - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                sh--;
                if (sh == 0) {
                    break;
                }
            }
        }
    }
    short* buf = new short[am];
    for (short i = 0; i < am / 2; i++) {
        buf[i] = mas[num][am - 1 - i];
        buf[i + am / 2] = mas[num][am - am / 2 - 1 - i];
        mas[num][am - 1 - i] = 0;
        mas[num][am - am / 2 - 1 - i] = 0;
    }
    if (am % 2 == 1) {
        buf[am - 1] = mas[num][0];
    }
    for (short i = 0; i < am / 2; i++) {
        mas[num][n3 - am + i] = buf[i];
        mas[num][n3 - am + am / 2 + i] = buf[i + am / 2];
    }
    if (am % 2 == 1) {
        mas[num][n3 - 1] = buf[am - 1];
    }
    delete[] arr;
    delete[] buf;
    buf = nullptr;
    arr = nullptr;
}

void out(short** mas, short num) {
    short pt = 0;
    while (mas[num][pt] == 0) {
        pt++;
    }
    for (short i = pt; i < n2; i++) {
        std::cout << mas[num][i];
    }
}


void rd(short** ten, short** bin, short n, short* a) {
    short k = 1;
    short schet = 2;
    short buf = 0;
    while (schet <= n) {
        for (short i = 0; i < schet; i++) {
            if (bin[i][n3 - 1 - k] == 0 && a[i] == 0) {
                buf++;
                if (schet - 1 + buf > n) {
                    break;
                }
                for (short j = 0; j < n2 / 2; j++) {
                    if (i == 0) break;
                    ten[schet - 1 + buf][j] = ten[i][j];
                    ten[schet - 1 + buf][n2 / 2 + j] = ten[i][n2 / 2 + j];
                    if (n2 % 2 == 1) {
                        ten[schet - 1 + buf][n2 - 1] = ten[i][n2 - 1];
                    }
                }
                ten[schet - 1 + buf][n2 - 1 - k] = 1;
            }
            else
            {
                a[i] = 1;
            }
            per(ten, bin, schet - 1 + buf);
        }
        schet += buf;
        k++;
        buf = 0;
    }
}

int main() {
    short n;

    std::cin >> n;

    short** ten = new short* [n1];
    short** bin = new short* [n1];
    short* a = new short[n1];
    for (short i = 0; i < n1; i++) {
        ten[i] = new short[n2];
        bin[i] = new short[n3];
        a[i] = 0;
        for (short j = 0; j < n2; j++) {
            ten[i][j] = 0;
            bin[i][j] = 0;
        }
        for (short j = n2; j < n3; j++) {
            bin[i][j] = 0;
        }
    }

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    rd(ten, bin, n, a);
    out(ten, n);

    for (int i = 0; i < n1; ++i) {
        delete[] ten[i];
        ten[i] = nullptr;

        delete[] bin[i];
        bin[i] = nullptr;
    }

    delete[] a;
    a = nullptr;

    return 0;
}