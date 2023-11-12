#include <iostream>
#include <cmath>

long long Func(long long n) {

	long long sum = 0, counter = 0, last_num;

	while (n / pow(2, counter) != 0) {

		last_num = n / powl(2, counter);
		last_num = last_num % 2 == 0 ? last_num - 1 : last_num;
		
		sum += (1 + last_num) / 2 * ((last_num - 1) / 2 + 1);

		counter++;
	}

	return sum;
}

int main() {

	long long k, n, sum;

	std::cin >> k;

	for (int _ = 0; _ < k; _++) {

		std::cin >> n;


		sum = Func(n);
		

		
		std::cout << sum << "\n";

	}



	return 0;
}