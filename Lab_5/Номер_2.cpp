#include <iostream>
#include <Windows.h>

int main() {

	int input = 1;

	std::cout << "N: 2\nTask: Find sum of elements' by formula: (sin(Bi) * cos(Bi))    \n";


	HINSTANCE Dliba;
	Dliba = LoadLibrary(L"Dynamiclib_2.dll");

	typedef int (*input_check) ();
	input_check Input_check;
	Input_check = (input_check)GetProcAddress(Dliba, "Input_check");

	typedef int (*sum) (int, int);
	sum Sum;
	Sum = (sum)GetProcAddress(Dliba, "Sum");

	typedef int (*input_check_n) (int, int, int);
	input_check_n Input_check_n;
	Input_check_n = (input_check_n)GetProcAddress(Dliba, "Input_check_n");

	typedef double (*input_check_num) (double, int, int, int);
	input_check_num Input_check_num;
	Input_check_num = (input_check_num)GetProcAddress(Dliba, "Input_check_num");

	typedef double* (*fullfill_B) (double*, int);
	fullfill_B Fullfill_B;
	Fullfill_B = (fullfill_B)GetProcAddress(Dliba, "Fullfill_B");


	typedef void* (*print_mass) (double*, int);
	print_mass Print_mass;
	Print_mass = (print_mass)GetProcAddress(Dliba, "Print_mass");

	typedef double (*solution) (double*, int, int);
	solution Solution;
	Solution = (solution)GetProcAddress(Dliba, "Solution");

	typedef void (*delete_mem) (double* B);
	delete_mem Delete_mem;
	Delete_mem = (delete_mem)GetProcAddress(Dliba, "Delete_mem");


	do {

		int n = 0;
		
		std::cout << "Enter n: ";
		n = Input_check();

		double* B = new double[n];
		B = Fullfill_B(B, n);

		double solution = Solution(B, 0, n - 1);

		std::cout << "The result is: " << solution << "\n";

		//Print_mass(B, n);

		Delete_mem(B);


		std::cout << "\nIf you want to run programm again, please type 1, in the other way type 0\n";
		std::cin >> input;
		if (input != 0) {
			input = 1;
		}

	} while (input);


	FreeLibrary(Dliba);

	return 0;
}