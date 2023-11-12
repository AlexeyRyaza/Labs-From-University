#include <iostream>
#include <cmath>


long long Func(long long i);


int main() {
	
    long long p, q, counter = 0;
	long long array[100] = {};

	std::cin >> p >> q;

	while (p > -1 && q > -1) {

		

		array[counter] = p;
		array[counter + 1] = q;

		counter += 2;

		std::cin >> p >> q;

	}


	int pos = 0;
	long long sum = 0;

	while(pos != counter){
			
		sum = 0;

		for (long long i = array[pos]; i <= array[pos + 1]; i++) {
		
			sum += Func(i);

		}
		
		std::cout << sum << "\n";

		pos += 2;
	}


	return 0;
}


long long Func(long long n) {

	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return Func(n / 10);
	}


}