#pragma once
#include <iostream>
#include<cmath>

using namespace std;

class square
{
private:
	double length;

public:
	square(double param_length) {
		this->length = param_length;
	}
	double getLength() {
		return length;
	}
	double getArea() {
		return pow(length, 2);
	}
	double getPerimeter() {
		return length * 4;
	}
};

