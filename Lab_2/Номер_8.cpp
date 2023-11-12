#include <iostream>
#include <cmath>

int main(){
	double a, b, c, p, q;
	std::cout << "Set a: ";
	std::cin >> a;
	std::cout << "Set b: ";
	std::cin >> b;
	std::cout << "Set c: ";
	std::cin >> c;
	std::cout << "Set p: ";
	std::cin >> p;
	std::cout << "Set q: ";
	std::cin >> q, '\n';

	int N;
	std::cout << "Choose number of equation(1, 2 or 3): " << "\n";
	std::cout << "1: ax^4 + bx^2 + c = 0" << "\n";
	std::cout << "2: ax^4 + bx^3 + cx^2 + bx + a = 0" << "\n";
	std::cout << "3: x^3 + px + q = 0" << "\n";
	std::cin >> N;

	double D, x_1, x_2, x_3, x_4, temp_1, temp_2, D_1, D_2;

	switch (N) {
		case 1:		// ax^4 + bx^2 + c = 0
			D = pow(b, 2) - 4 * a * c;
			if (a == 0 && b == 0 && c == 0) {
				std::cout << "X can be any";
			}			
			else if (a == 0 && b == 0 && c != 0) {
				std::cout << "No solution";
			}
			else if (a == 0) {
				x_1 = sqrt(-c);
				x_2 = -sqrt(-c);
				std::cout << "x1 = " << x_1 << "\n";
				std::cout << "x2 = " << x_2 << "\n";
			}
			else if (D >= 0){
				x_1 = (-b + sqrt(D)) / (2 * a);
				x_2 = (-b - sqrt(D)) / (2 * a);
				
				if (x_1 >= 0) {
					x_3 = -(sqrt(x_1));
					x_1 = sqrt(x_1);

					std::cout << "x1 = " << x_1 << "\n";
					std::cout << "x2 = " << x_3 << "\n";
				}

				if (x_2 >= 0) {

					x_4 = -(sqrt(x_2));
					x_2 = sqrt(x_2);

					std::cout << "x3 = " << x_2 << "\n";
					std::cout << "x4 = " << x_4 << "\n";
				}
				
				
				
			}
			else { 
				std::cout << "Solution doesn't exist";
			}
			break;
		case 2:		// ax^4 + bx^3 + cx^2 + bx + a = 0
			D = pow(b, 2) - 4 * a * (c - 2 * a);


			if (a == 0 && b == 0 && c == 0) {
				std::cout << "X can be any";
			}
			else if (a == 0 && b == 0) {
				std::cout << "x = " << 0;
			}
			else if (a == 0) {
				D = pow(c, 2) - (4 * b * b);

				x_1 = 0;
				x_2 = (-c + sqrt(D)) / (2 * b);
				x_3 = (-c - sqrt(D)) / (2 * b);

				std::cout << "x1 = " << x_1 << "\n";
				std::cout << "x2 = " << x_2 << "\n";
				std::cout << "x3 = " << x_3 << "\n";


			}

			else if (D >= 0) {
				temp_1 = (-b + sqrt(D)) / (2 * a);
				temp_2 = (-b - sqrt(D)) / (2 * a);

				D_1 = pow(temp_1, 2) - 4;
				if (D_1 >= 0) {
					x_1 = (temp_1 + sqrt(D_1)) / 2;
					x_2 = (temp_1 - sqrt(D_1)) / 2;

					std::cout << "x1 = " << x_1 << "\n";
					std::cout << "x2 = " << x_2 << "\n";
				}
				D_2 = pow(temp_2, 2) - 4;
				if (D_2 >= 0) {
					x_3 = (temp_2 + sqrt(D_2)) / 2;
					x_4 = (temp_2 - sqrt(D_2)) / 2;
					std::cout << "x3 = " << x_3 << "\n";
					std::cout << "x4 = " << x_4 << "\n";
				
				}
			}
			else {
				std::cout << "Solution doesn't exist";
			}
			
			break;
		
		case 3:		// x^3 + px + q = 0
			double a_1, b_1, A, B;
			if (((pow(q, 2) / 4) + pow(p, 3) / 27) < 0) {
				x_1 = 2 * sqrt(-p / 3) * cos((1.0 / 3) * acos((3 * q) / (2 * p) * sqrt(-3.0 / p)) - 0 * (2 * acos(-1)) / 3);
				x_2 = 2 * sqrt(-p / 3) * cos((1.0 / 3) * acos((3 * q) / (2 * p) * sqrt(-3.0 / p)) - 1 * (2 * acos(-1)) / 3);
				x_3 = 2 * sqrt(-p / 3) * cos((1.0 / 3) * acos((3 * q) / (2 * p) * sqrt(-3.0 / p)) - 2 * (2 * acos(-1)) / 3);

				std::cout << "x1 = " << x_1 << "\n";
				std::cout << "x2 = " << x_2 << "\n";
				std::cout << "x3 = " << x_3 << "\n";

				
			}
			else {
				a_1 = (-q / 2) + sqrt((pow(q, 2) / 4) + pow(p, 3) / 27);
				b_1 = (-q / 2) - sqrt((pow(q, 2) / 4) + pow(p, 3) / 27);

				if (a < 0) {
					a_1 = abs(a_1);
					A = -pow(a_1, (double)1 / 3);
				}
				else {
					A = pow(a_1, (double)1 / 3);
				}
				if (b_1 < 0) {
					b_1 = abs(b_1);
					B = -pow(b_1, (double)1 / 3);
				}
				else {
					B = pow(b_1, (double)1 / 3);
				}

				x_1 = A + B;
				std::cout << "x = " << x_1;
			}
			break;
	}




	return 0;
}