#include < iostream>

int main() {
	double x;
	std::cout << "Set x: ";
	std::cin >> x;

	//problem_1 = 23x^3 + 69x^2 + 32x + 8
	//problem_2 = -23x^3 + 69x^2 - 32x + 8

	double x_2 = x * x; 

	double st = 69 * x_2 + 8; 
	double n_st = x * (23 * x_2 + 32);

	double solut_1 = st + n_st; 
	double solut_2 = st - n_st;

	std::cout << "Solution to the first problem: " << solut_1 << "\n";
	std::cout << "Solution to the srcond problem: " << solut_2;



	return 0;
}