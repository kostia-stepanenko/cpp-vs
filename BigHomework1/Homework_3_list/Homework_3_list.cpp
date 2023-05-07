

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


class Term {

private:
    double coeff;
    int exp;

public:

    Term(double coeff, int exp) {
        this->coeff = coeff;
        this->exp = exp;
    }

    double getCoeff() const {
        return this->coeff;
    }

    int getExp() const {
        return this->exp;
    }

    double eval(double x) const {
        return this->coeff * pow(x, this->exp);
    }

    friend ostream& operator<<(ostream& os, const Term& t) {

        if (t.exp == 0.0) {
            os << t.coeff;
        }
        else if (t.exp == 1.0) {
            os << t.coeff << "*X";
        }
        else {
            os << t.coeff << "*X^" << t.exp;
        }

        return os;
    }
};


class Polynomial {
private:
    list<Term> terms;

public:

    Polynomial() {}

    void addTerm(Term newTerm) {
        this->terms.push_back(newTerm);
    }

    double evaluate(double x) {

        double res = 0.0;

        for (const Term& t : this->terms) {
            res += t.eval(x);
        }

        return res;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {

        int index = 0;
        for (const Term& t : p.terms) {

            if (t.getCoeff() == 0.0) {
                continue;
            }

            if (t.getCoeff() > 0.0) {
                if (index != 0) {
                    os << " + ";
                }
                os << t;
            }
            else {
                os << " " << t;
            }

            ++index;
        }

        return os;
    }
};

int main(){


    Polynomial p;
    p.addTerm(Term(-3.15, 5));
    p.addTerm(Term(12, 4));
    p.addTerm(Term(0, 2));
    p.addTerm(Term(-18, 1));
    p.addTerm(Term(13, 0));


    cout << p << endl;

    cout << "homework 3 polinoms as list done" << endl;

    return 0;
}

