#include <iostream>
#include <cmath>

int main() {
	int i = 1;
	double a, b, sum = 0;
	
	while (i < 31) {

		if (i % 2 == 0) {
			a = (double)i / 2;
			b = pow(i, 3);
		}
		else {
			a = i;
			b = pow(i, 2);
		}
		
		sum += pow(a - b, 2);

		i++;
	}

	std::cout << "Sum = " << sum;


}