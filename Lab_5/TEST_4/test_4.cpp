#include "pch.h"
#include <string>


int search_for_zeros(double** matrix, int N, int M);



TEST(test_1) {
	
	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new double[3];
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = j;
		}
	}

	ASSERT_EQ(search_for_zeros(matrix, 3, 3), 3);
	///ASSERT_STREQ(print_zeros(matrix, 3, 3, 3), "There is a zero with indexes: 0 0\nThere is a zero with indexes : 1 0\nThere is a zero with indexes : 2 0\nTotal number of zeros: 3\n");
	 
}

TEST(all_zeros) {

	double** matrix = new double* [3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new double[3];
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = 0;
		}
	}

	ASSERT_EQ(search_for_zeros(matrix, 3, 3), 9);
}


int search_for_zeros(double** matrix, int N, int M) {

	int counter = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) {
				counter++;
			}
		}
	}
	
	if (counter != 0) {
		return counter;
	}
	else {
		std::cout << "No zeros found";
	}
}