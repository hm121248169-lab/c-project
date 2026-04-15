#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class complex {
private:
    double real;
    double imaginary;

public:
    complex(double r = 0, double i = 0) {
        real = r;
        imaginary = i;
    }

    complex operator+(const complex& other) const {
        return complex(real + other.real, imaginary + other.imaginary);
    }

    complex operator-(const complex& other) const {
        return complex(real - other.real, imaginary - other.imaginary);
    }

    bool operator==(const complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    bool operator!=(const complex& other) const {
        return (real != other.real || imaginary != other.imaginary);
    }

    bool operator<(const complex& other) const {
        if (imaginary != 0 || other.imaginary != 0) {
            double mod1 = sqrt(real * real + imaginary * imaginary);
            double mod2 = sqrt(other.real * other.real + other.imaginary * other.imaginary);
            return mod1 < mod2;
        } else {
            return real < other.real;
        }
    }

    bool operator>(const complex& other) const {
        if (imaginary != 0 || other.imaginary != 0) {
            double mod1 = sqrt(real * real + imaginary * imaginary);
            double mod2 = sqrt(other.real * other.real + other.imaginary * other.imaginary);
            return mod1 > mod2;
        } else {
            return real > other.real;
        }
    }

    void setReal(double realVal) {
        real = realVal;
    }

    void setImag(double imagVal) {
        imaginary = imagVal;
    }

    double getReal() const {
        return real;
    }

    double getImag() const {
        return imaginary;
    }
};

istream& operator>>(istream& is, complex& c) {
    double real, imag;
    char c1, c2;
    is >> real >> c1 >> imag >> c2;
    if (c1 == '-') {
        imag = -imag;
    }
    c.setReal(real);
    c.setImag(imag);
    return is;
}

ostream& operator<<(ostream& os, const complex& c) {
    os << fixed << setprecision(2);
    if (c.getImag() >= 0) {
        os << c.getReal() << "+" << c.getImag() << "i";
    } else {
        os << c.getReal() << c.getImag() << "i";
    }
    return os;
}

int main()
{
    complex c1, c2, c3, c4, c5;
    cin >> c1 >> c2;
    c3 = c1 + c2;
    c4 = c1 - c2;
    if (c3 != c4)
    {
        if (c3 < c4)
        {
            cout << "c3 is less than c4";
            c5 = c4 - c3;
        }
        if (c3 > c4)
        {
            cout << "c3 is greater than c4";
            c5 = c3 - c4;
        }
    }
    if (c3 == c4)
    {
        cout << "c3 and c4 are equal";
        c5 = c4;
    }
    cout << endl;
    cout << c5;
    return 0;
}