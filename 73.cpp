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

    void tongfen(fraction& other) {
        int common_den = denominator * other.denominator;
        numerator *= other.denominator;
        other.numerator *= denominator;
        denominator = common_den;
        other.denominator = common_den;
    }

public:
    fraction() : numerator(0), denominator(1) {}

    fraction(int num, int den) {
        if (den == 0) {
            numerator = num;
            denominator = 1;
        } else {
            numerator = num;
            denominator = den;
        }
        simplify();
    }

    void setdata(int num, int den) {
        if (den == 0) {
            numerator = num;
            denominator = 1;
        } else {
            numerator = num;
            denominator = den;
        }
        simplify();
    }

    void getdata(int& num, int& den) const {
        num = numerator;
        den = denominator;
    }

    fraction operator+(const fraction& other) const {
        fraction temp1 = *this;
        fraction temp2 = other;
        temp1.tongfen(temp2);
        int new_num = temp1.numerator + temp2.numerator;
        return fraction(new_num, temp1.denominator);
    }

    fraction operator-(const fraction& other) const {
        fraction temp1 = *this;
        fraction temp2 = other;
        temp1.tongfen(temp2);
        int new_num = temp1.numerator - temp2.numerator;
        return fraction(new_num, temp1.denominator);
    }

    fraction operator*(const fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return fraction(new_num, new_den);
    }

    fraction operator/(const fraction& other) const {
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return fraction(new_num, new_den);
    }
};

istream& operator>>(istream& in, fraction& f) {
    int num, den;
    in >> num >> den;
    f.setdata(num, den);
    return in;
}

ostream& operator<<(ostream& out, const fraction& f) {
    int num, den;
    f.getdata(num, den);
    if (num == 0 || den == 1) {
        out << num << endl;
    } else {
        out << num << "/" << den << endl;
    }
    return out;
}

int main()
{
    fraction x1,x2(2,7),x3,y1,y2,z1,z2,z3,z4,z5;
   cin>>x3>>y1>>y2;
   z1=x3+y1;      
   z2=x3-y1;       
   z3=x3*y2;       
   z4=x3/y2; 
   x1.setdata(5,7);          
   z5=x1+x2;     
   cout<<z1<<z2<<z3<<z4<<z5;
  return 0;
}