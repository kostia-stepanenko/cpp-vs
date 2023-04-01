#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include<math.h>


using namespace std;
class circle
{

private:
	double radius;

public :
	circle(double param_radius) {
		this->radius = param_radius;
	}

	double getRadius() {
		return radius;
	}
	double getDiameter() {
		return 2 * radius;
	}
	double getArea() {
		return M_PI * pow(radius, 2);
	}
	double getPerimeter() {
		return M_PI * 2 * radius;
	}
};

