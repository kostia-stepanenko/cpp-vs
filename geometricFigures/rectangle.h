#pragma once
#include <iostream>

using namespace std;

class rectangle
{
private :
	double length;
	double width;
public:
	rectangle(double param_length, double param_width) {
		if (param_length <= 0.0 || param_width <= 0.0) {
			throw invalid_argument("Negative length/width detected");
		}

		this->length = param_length;
		this->width = param_width;
	}

	double getLength() {
		return length;
	}

	void setLength(double lengthValue) {
		if (lengthValue <= 0.0) {
			throw invalid_argument("Negative length detected");
		}
		this->length = lengthValue;
	}

	double getWidth() {
		return width;
	}
	double getArea() {
		return width * length;

	}
	double getPerimeter() {
		if (length > 0 && width > 0) {
			return width * 2 + length * 2;
		}
		else
			cout << "error: negative width or length value  " << endl;
		return 0;
	}
};

