#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	long long k, x, y;
	long double dist_1, dist_2, dist_3, dist_4, min_1, min_2;

	std::cin >> k >> x >> y;



	if (k > 0) {
		if ((x < k && y < k) && (x > 0 && y > 0)) {
			dist_1 = y;
			dist_2 = k - x;
			dist_3 = k - y;
			dist_4 = x;

			if (dist_1 <= dist_2) {
				min_1 = dist_1;
			}
			else {
				min_1 = dist_2;
			}

			if (dist_3 <= dist_4) {
				min_2 = dist_3;
			}
			else {
				min_2 = dist_4;
			}

			if (min_1 < min_2) {
				std::cout << std::setprecision(22) << min_1;
			}
			else {
				std::cout << std::setprecision(22) << min_2;
			}
		}
		else if (((x > k && y < k) || (x < k && y > k)) && (x > 0 && y > 0)) {
			if (x > y) {
				std::cout << std::setprecision(22) << x - k;
			}
			else {
				std::cout << std::setprecision(22) << y - k;
			}
		}
		else if ((x > k || y > k) && (x > 0 && y > 0)) {
			min_1 = sqrt(pow(x - k, 2) + pow(y - k, 2));
			std::cout << std::setprecision(22) << min_1;
		}
		else if ((x < 0 && y > 0 && y < k) || (y < 0 && x > 0 && x < k)) {
			if (x < y) {
				std::cout << std::setprecision(22) << -x;
			}
			else {
				std::cout << std::setprecision(22) << -y;
			}
		}
		else if ((x < 0 && y > 0 && y > k) || (y < 0 && x > 0 && x > k)) {
			if (x < 0) {
				min_1 = sqrt(pow(x, 2) + pow(k - y, 2));
				std::cout << min_1;
			}
			else if(y < 0){
				min_1 = sqrt(pow(k - x, 2) + pow(y, 2));
				std::cout << min_1;
			}
		}

		else if (x < 0 && y < 0) {
			min_1 = sqrt(pow(x, 2) + pow(y, 2));
			std::cout << std::setprecision(22) << min_1;
		}
	}
	else {
		if ((x > k && y > k) && (x < 0 && y < 0)) {
			dist_1 = -y;
			dist_2 = -(k - x);
			dist_3 = -(k - y);
			dist_4 = -x;

			if (dist_1 <= dist_2) {
				min_1 = dist_1;
			}
			else {
				min_1 = dist_2;
			}

			if (dist_3 <= dist_4) {
				min_2 = dist_3;
			}
			else {
				min_2 = dist_4;
			}

			if (min_1 < min_2) {
				std::cout << std::setprecision(22) << min_1;
			}
			else {
				std::cout << std::setprecision(22) << min_2;
			}
		}
		else if (((x > k && y < k) || (x < k && y > k)) && (x < 0 && y < 0)) {
			if (x > y) {
				std::cout << std::setprecision(22) << k - y;
			}
			else {
				std::cout << std::setprecision(22) << k - x;
			}
		}
		else if ((x < k && y < k) && (x < 0 && y < 0)) {
			min_1 = sqrt(pow(x - k, 2) + pow(y - k, 2));
			std::cout << std::setprecision(22) << min_1;
		}
		else if ((x < 0 && y > 0 && x > k) || (y < 0 && x > 0 && y > k)) {   
			if (x < y) {
				std::cout << std::setprecision(22) << y;
			}
			else {
				std::cout << std::setprecision(22) << x;
			}
		}

		else if ((x > 0 && y < 0 && y < k) || (y > 0 && x < 0 && x < k)) {
			if (x < 0) {
				min_1 = sqrt(pow(k - x, 2) + pow(y, 2));
				std::cout << min_1;
			}
			else {
				min_1 = sqrt(pow(x, 2) + pow(k - y, 2));
				std::cout << min_1;
			}
		}

		else if (x > 0 && y > 0) {
			min_1 = sqrt(pow(x, 2) + pow(y, 2));
			std::cout << std::setprecision(22) << min_1;
		}
	}
	return 0;
}