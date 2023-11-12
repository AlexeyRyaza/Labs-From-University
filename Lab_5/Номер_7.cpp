#include <iostream>

long long Func(long long k, long long n, long long t);

int main() {
	
	long long k, n, t, counter = 1;



	do {

		std::cin >> k >> n >> t;

		if (k == 0 && n == 0 && t == 0) {
			
			break;
			
		}

		t = pow(10, t);

		long long answer = Func(k, n, t);
	
		std::cout << "Case #" << counter << ": " << answer << "\n";

		counter++;

	} while (1);

	return 0;
}



long long Func(long long k, long long n, long long t) {

	
	if (n == 1) {
		
		return k;

	}
	else {
	
		long long answer = Func(k, n / 2, t);


		if (n % 2 == 0) {
			answer = (answer * answer) % t;
		}
		else {
			answer = ((answer * answer) % t * k) % t;
		}
		
		return answer;
	}

}
