#include <iostream>
#include <cmath>


int main() {
	double x1, y1, x2, y2, x3, y3;
	double pi = 3.14159;

	std::cout << "Set x1: ";
	std::cin >> x1, "\n";
	std::cout << "Set y1: ";
	std::cin >> y1, "\n";

	std::cout << "Set x2: ";
	std::cin >> x2, "\n";
	std::cout << "Set y2: ";
	std::cin >> y2, "\n";

	std::cout << "Set x3: ";
	std::cin >> x3, "\n";
	std::cout << "Set y3: ";
	std::cin >> y3, "\n", "\n";


	double length_1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	double length_2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	double length_3 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	std::cout << "Length of the first side: " << length_1 << "\n";
	std::cout << "Length of the second side: " << length_2 << "\n";
	std::cout << "Length of the third side: " << length_3 << "\n" << "\n";


	double p = (length_1 + length_2 + length_3) / 2;
	double square = sqrt(p * (p - length_1) * (p - length_2) * (p - length_3));

	double height_1 = 2 * square / length_1;
	double height_2 = 2 * square / length_2;
	double height_3 = 2 * square / length_3;
	std::cout << "Height to the first side: " << height_1 << "\n";
	std::cout << "Height to the second side: " << height_2 << "\n";
	std::cout << "Height to the third side: " << height_3 << "\n" << "\n";


	double median_1 = sqrt((2 * pow(length_2, 2) + 2 * pow(length_3, 2) - pow(length_1, 2))) / 2;
	double median_2 = sqrt((2 * pow(length_1, 2) + 2 * pow(length_3, 2) - pow(length_2, 2))) / 2;
	double median_3 = sqrt((2 * pow(length_1, 2) + 2 * pow(length_2, 2) - pow(length_3, 2))) / 2;
	std::cout << "Median to the first side: " << median_1 << "\n";
	std::cout << "Median to the second side: " << median_2 << "\n";
	std::cout << "Median to the third side: " << median_3 << "\n" << "\n";


	double bisector_1 = 2 * sqrt(length_1 * length_3 * p * (p - length_2)) / (length_1 + length_3);
	double bisector_2 = 2 * sqrt(length_1 * length_2 * p * (p - length_3)) / (length_1 + length_2);
	double bisector_3 = 2 * sqrt(length_2 * length_3 * p * (p - length_1)) / (length_2 + length_3);
	std::cout << "Bisector of the first angle: " << bisector_1 << "\n";
	std::cout << "Bisector of the second angle: " << bisector_2 << "\n";
	std::cout << "Bisector of the third angle: " << bisector_3 << "\n" << "\n";


	double R = length_1 * length_2 * length_3 / (square * 4);
	double r = square / p;

	double radians_1 = asin(length_2 / (2 * R));
	double radians_2 = asin(length_3 / (2 * R));
	double radians_3 = asin(length_1 / (2 * R));
	double degrees_1 = radians_1 * 180 / pi;
	double degrees_2 = radians_2 * 180 / pi;
	double degrees_3 = radians_3 * 180 / pi;
	std::cout << "Radian value of the first angle: " << radians_1 << "\n";
	std::cout << "Degree value of the first angle: " << degrees_1 << "\n";
	std::cout << "Radian value of the second angle: " << radians_2 << "\n";
	std::cout << "Degree value of the second angle: " << degrees_2 << "\n";
	std::cout << "Radian value of the third angle: " << radians_3 << "\n";
	std::cout << "Degree value of the third angle: " << degrees_3 << "\n" << "\n";

	
	std::cout << "Radius of inscribed circle: " << r << "\n";
	std::cout << "Radius of circumcircle: " << R << "\n" << "\n";


	double incircle_sq = pi * pow(r, 2);
	double incircle_len = 2 * pi * r;
	double outcircle_sq = pi * pow(R, 2);
	double outcircle_len = 2 * pi * R;

	std::cout << "Square of circumcircle: " << outcircle_sq << "\n";
	std::cout << "Length of circumcircle: " << outcircle_len << "\n";
	std::cout << "Square of inscribed circle: " << incircle_sq << "\n";
	std::cout << "Length of inscribed circle: " << incircle_len << "\n" << "\n";

	
	double perimiter = length_1 + length_2 + length_3;
	double square_1 = height_1 * length_1 / (double)2;
	double square_2 = length_1 * length_2 * length_3 / (4 * R);
	double square_3 = p * r;
	
	std::cout << "Perimiter of triangle: " << perimiter << "\n";
	std::cout << "Square of triangle: " << square;

	return 0;
}