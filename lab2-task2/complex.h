#pragma once

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



