#include <iostream>
#include "complex.h"

using namespace std;


int main()
{

    complex number(2, 3);
    complex conj = number.conjugate();
    cout << "The conjugate number is: " << conj << endl;

    cout << endl << "Add" << endl;

    // (3 − 2i)
    complex first(3, -2);
    cout << "first: " << first << endl;

    // (− 4 + 3i)
    complex second(-4, 3);
    cout << "second: " << second << endl;

    // -6 + 17i
    cout << "mul: " << complex::multiply(first, second) << endl;

    cout << "div: " << complex::divide(first, second) << endl;

}
