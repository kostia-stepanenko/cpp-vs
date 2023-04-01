

#include <iostream>

using namespace std;

template <class T>
class Point
{
private:
	T coord_x;
	T coord_y;

public:
	Point (int xValue,int yValue){
		this->coord_x = xValue;
		this->coord_y = yValue;
	}
	T getY() {
		return coord_y;
	}
	T getX() {
		return coord_x;
	}
};

int main()
{
	Point <float> p1(10.0,23.4);
	cout << "point coords are "<<p1.getX()<<endl;

}
