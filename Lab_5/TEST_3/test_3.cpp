#include "pch.h"

long long multiplication(long long* array, long long counter);
    


TEST(ord_1) {
    long long array_1[3] = { 2, 4, 8 };
    ASSERT_EQ(multiplication(array_1, 3), 64);
}

TEST(BIG_NUMS) {
    long long array_2[5] = { 100, 200, 300, 400, 500 };
    ASSERT_EQ(multiplication(array_2, 5), 1.2e12);
}

TEST(ZEROS) {
    long long array_3[5] = { 0, 0, 0, 0, 0 };
    ASSERT_EQ(multiplication(array_3, 5), 0);
}



long long multiplication(long long* array, long long counter) {
    long long mult = 1;
    for (long long i = 0; i < counter; i++) {

        mult *= array[i];

    }

    return mult;
}