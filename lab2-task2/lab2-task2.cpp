#include <iostream>
#include<cmath>

using namespace std;


class complex {

private:
    double re;
    double im;

public:
    complex() {
        this->re = 0.0;
        this->im = 0.0;
    }

    complex(double param_re, double param_im) {
        this->re = param_re;
        this->im = param_im;
    }

    double getRe() {
        return re;
    }

    double getIm() {
        return im;
    }

    complex conjugate() {
        complex conjugate(re, -im);
        return conjugate;
    }

    static complex add(complex first, complex second) {
        return complex(first.re + second.re, first.im + second.im);
    }

    static complex multiply(complex first, complex second) {

        double resRe = first.re * second.re - first.im * second.im;
        double resIm = first.re * second.im + first.im * second.re;

        return complex(resRe, resIm);
    }
    static complex divide(complex first, complex second) {

        double resRe = (first.re * second.re + first.im * second.im) / (pow(second.re, 2) + pow(second.im, 2));
        double resIm = (first.im * second.re - first.re * second.im) / (pow(second.re, 2) + pow(second.im, 2));

        return complex(resRe, resIm);
    }


    friend ostream& operator<<(ostream& os, const complex& val) {
        if (val.im < 0) {
            os << val.re << val.im << "*i";
        }
        else {
            os << val.re << " + " << val.im << "*i";
        }
        return os;
    }

};


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
