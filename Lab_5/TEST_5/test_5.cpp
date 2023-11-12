#include "pch.h"

double count_average(int counter, int* array);



TEST(Positive) {
	  
	int array_1[3] = { 1, 3, 5 };

	ASSERT_EQ(count_average(3, array_1), 3);

}
TEST(Negative) {

	int array_2[5] = { -1, -11, -7, -9, -33 };

	ASSERT_EQ(count_average(5, array_2), -12.2);
}
TEST(Zeros) {

	int array_3[5] = { 0, 0, 0, 0, 0 };

	ASSERT_EQ(count_average(5, array_3), 0);
}



double count_average(int counter, int* array) {
	double average = 0;

	for (int i = 0; i < counter; i++) {

		average += array[i];

	}

	average /= counter;

	return average;
}
