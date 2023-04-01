#pragma once

#include <iostream>
#include<cmath>

using namespace std;

class ratio
{
private:
    double num;
    double denum;

public:
    ratio() {
        this->num = 0.0;
        this->denum = 0.0;
    }

    ratio(double param_num, double param_denum) {

        int div = gcd( abs(param_num), abs(param_denum)); // gcd(param_num, param_denum);

        this->num = param_num / div;
        this->denum = param_denum /div;
    }

    double getNum() {
        return num;
    }
    double getDenum() {
        return denum;
    }

    unsigned int gcd(unsigned int n1, unsigned int n2) {
        return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
    }


    static ratio multiply(ratio first,ratio second) {
        double resNum = first.num*second.num;
        double resDenum = first.denum*second.denum;
        return ratio (resNum, resDenum);
    }

    static ratio divide(ratio first, ratio second) {
        double resNum = first.num * second.denum;
        double resDenum = first.denum * second.num;
        return ratio(resNum, resDenum);
    }

    static ratio addition(ratio first, ratio second) {
        if (first.denum == second.denum) {
            double resNum = first.num + second.num;
            double resDenum = first.denum;
            return ratio(resNum, resDenum);
        }
        else {
            double resNum = first.num * second.denum + second.num * first.denum;
            double resDenum = first.denum * second.denum;
            if (resNum == resDenum) {
                resNum = 1.0;
                resDenum = 1.0;
            }

            return ratio(resNum, resDenum);
        }
    }
    
    static ratio subtraction(ratio first, ratio second) {
        if (first.denum = second.denum) {
            double resNum = first.num - second.num;
            double resDenum = first.denum;
            return ratio(resNum, resDenum);
        }
        else {
            double resNum = first.num * second.denum - second.num * first.denum;
            double resDenum = first.denum * second.denum;
            if (resNum == resDenum) {
                resNum = 1;
                resDenum = 1;
            }

            return ratio(resNum, resDenum);
        }
    }
};

