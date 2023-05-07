

#include <iostream>
#include <cstdlib>
#include <list>
#include <complex>

using namespace std;


class Term {

private:
    double coeff;
    int exp;

public:

    Term(const Term& other) {
        this->coeff = other.coeff;
        this->exp = other.exp;
    }

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

    Polynomial sum(Polynomial& second) {
        Polynomial res;

        auto firstIt = this->terms.begin();
        auto secondIt = second.terms.begin();

        while (firstIt != this->terms.end() || secondIt != second.terms.end()) {

            if (firstIt == this->terms.end()) {
                res.addTerm(Term(*secondIt));
                ++secondIt;
                continue;
            }

            if (secondIt == second.terms.end()) {
                res.addTerm(Term(*firstIt));
                ++firstIt;
                continue;
            }

            // exp1 == exp2
            if (firstIt->getExp() == secondIt->getExp()) {

                double curCoeff = firstIt->getCoeff() + secondIt->getCoeff();

                res.addTerm(Term(curCoeff, firstIt->getExp()));

                ++firstIt;
                ++secondIt;
            }

            // exp1 > exp2
            else if (firstIt->getExp() > secondIt->getExp()) {
                res.addTerm(Term(*firstIt));
                ++firstIt;
            }

            // exp1 < exp2
            else {
                res.addTerm(Term(*secondIt));
                ++secondIt;
            }
        }

        return res;
    }

    Polynomial mulByTerm(const Term& termToMul)  {
        Polynomial res;

        for (const Term& cur : this->terms) {
            double newCoeff = termToMul.getCoeff() * cur.getCoeff();
            int newExp = termToMul.getExp() + cur.getExp();

            res.addTerm(Term(newCoeff, newExp));
        }

        return res;
    }


    Polynomial mul(Polynomial& second) {
        Polynomial res;

        for (const Term& secondTerm : second.terms) {
            Polynomial partialRes = this->mulByTerm(secondTerm);
            res = res.sum(partialRes);
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

    /*
    Polynomial p1;
    p1.addTerm(Term(3, 3));
    p1.addTerm(Term(2, 2));
    p1.addTerm(Term(6, 1));
    p1.addTerm(Term(5, 0));
    

    cout << "p1: " << p1 << endl;

    cout << "p(X) = " << p1.evaluate(12.34) << endl;

    Polynomial p2;
    p2.addTerm(Term(1, 4));
    p2.addTerm(Term(1, 2));
    p2.addTerm(Term(3, 1));
    p2.addTerm(Term(2, 0));

    Polynomial sumRes = p1.sum(p2);

    cout << "p2: " << p2 << endl;
    cout << "p1 + p1: " << sumRes << endl;

    Polynomial prodRes = p1.mul(p2);

    cout << "p1 * p2: " << prodRes << endl;
    */

    cout << "homework 3 polinoms as list done" << endl;

    return 0;
}

