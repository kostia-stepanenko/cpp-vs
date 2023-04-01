
#include <iostream>
#include "rectangle.h"
#include "square.h"
#include "circle.h"

using namespace std;

int main()
{
	try {
		rectangle r1(12, 20);
		double  area = r1.getArea();
		cout << "The rectangle area is : " << area << endl;

		double perimeter = r1.getPerimeter();
		cout << "The rectangle perimeter is : " << perimeter << endl;

		circle c1(10);
		double c_area = c1.getArea();
		cout << "The circle area is : " << c_area << endl;

		double c_perimeter = c1.getPerimeter();
		cout << "The circle perimeter is : " << c_perimeter << endl;

		square s1(5);
		double s_area = s1.getArea();
		cout << "The square area is : " << s_area << endl;

		double s_perimeter = s1.getPerimeter();
		cout << "The circle perimeter is : " << s_perimeter << endl;
	}
	catch (exception& ex) {
		cerr << ex.what() << endl;
	}
}
