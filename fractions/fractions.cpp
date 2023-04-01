

#include <iostream>
#include "ratio.h"

using namespace std;

int main()
{
	ratio first (2, 2);
	ratio second (3, 4);
	ratio res = ratio::multiply(first, second);

	cout << "Multiplication result is:" << res.getNum() << "/" << res.getDenum() << endl;
}
