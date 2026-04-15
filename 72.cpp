#include <iostream>
using namespace std;

class fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    fraction() : numerator(0), denominator(1) {}

    fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            denominator = 1;
        }
        simplify();
    }

    fraction add(const fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return fraction(new_num, new_den);
    }

    fraction subtract(const fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return fraction(new_num, new_den);
    }

    fraction multiply(const fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return fraction(new_num, new_den);
    }

    fraction divide(const fraction& other) const {
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return fraction(new_num, new_den);
    }

    fraction operator+(const fraction& other) const {
        return add(other);
    }

    fraction operator-(const fraction& other) const {
        return subtract(other);
    }

    fraction operator*(const fraction& other) const {
        return multiply(other);
    }

    fraction operator/(const fraction& other) const {
        return divide(other);
    }

    void input() {
        cin >> numerator >> denominator;
        if (denominator == 0) {
            denominator = 1;
        }
        simplify();
    }

    void output() const {
        if (numerator == 0 || denominator == 1) {
            cout << numerator << endl;
        } else {
            cout << numerator << "/" << denominator << endl;
        }
    }
};

int main()
{
    fraction x1, x2(2, 7), x3, y1, y2, z1, z2, z3, z4, z5;
    x3.input();

    y1.input();

    y2.input();

    z1 = x3 + y1;
    z1.output();
    z2 = x3 - y1;
    z2.output();    

    z3 = x3*y2;

    z3.output();    
    z4 = x3 / y2;
    z4.output();    

    z5 = x1 + x2;
    z5.output();

    return 0;
}