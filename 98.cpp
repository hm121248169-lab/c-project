#include <iostream>
using namespace std;

class fraction
{
private:
    int numer;  //分子
    int denom;  //分母
    //求最大公约数
    int gcd(int a, int b)
    {
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
public:
    //1.构造函数
    fraction()
    {
        numer = 0;
        denom = 1;
    }
    fraction(int n, int d)
    {
        numer = n;
        if (d == 0)
            denom = 1;
        else
            denom = d;
        reduce(); //创建完毕就约分
    }

    //约分
    void reduce()
    {
        int g = gcd(numer, denom);
        numer /= g;
        denom /= g;
        if (denom < 0) //分母保证正数
        {
            numer = -numer;
            denom = -denom;
        }
    }
    //通分，返回公分母                    
    void common(fraction &f2)
    {
        int g = gcd(denom, f2.denom);
        int lcm = denom / g * f2.denom;
        numer = numer * (lcm / denom);
        f2.numer = f2.numer * (lcm / f2.denom);
        denom = lcm;
        f2.denom = lcm;
    }

    void setdata(int n, int d)
    {
        numer = n;
        if (d == 0) denom = 1;
        else denom = d;
        reduce();
    }
    void getdata(int &n, int &d)
    {
        n = numer;
        d = denom;
    }

    //运算符重载，成员函数形式
    fraction operator+(fraction f2)
    {
        fraction temp1(*this);
        fraction temp2 = f2;
        temp1.common(temp2);
        fraction res(temp1.numer + temp2.numer, temp1.denom);
        res.reduce();
        return res;
    }
    fraction operator-(fraction f2)
    {
        fraction temp1(*this);
        fraction temp2 = f2;
        temp1.common(temp2);
        fraction res(temp1.numer - temp2.numer, temp1.denom);
        res.reduce();
        return res;
    }
    fraction operator*(fraction f2)
    {
        fraction res(numer * f2.numer, denom * f2.denom);
        res.reduce();
        return res;
    }
    fraction operator/(fraction f2)
    {
        fraction res(numer * f2.denom, denom * f2.numer);
        res.reduce();
        return res;
    }
};
//全局函数重载 >> 和 <<，不能用友元，借助getdata
istream& operator >> (istream &is, fraction &fr)
{
    int n, d;
    is >> n >> d;
    fr.setdata(n, d);
    return is;
}
ostream& operator << (ostream &os, fraction &fr)
{
    int n, d;
    fr.getdata(n, d);
    if (n == 0 || d == 1)
    {
        os << n << endl;
    }
    else
    {
        os << n << "/" << d << endl;
    }
    return os;
}

int main()
{
    fraction x1, x2(2, 7), x3, y1, y2, z1, z2, z3, z4, z5;
    cin >> x3 >> y1 >> y2;
    z1 = x3 + y1;
    z2 = x3 - y1;
    z3 = x3 * y2;
    z4 = x3 / y2;
    x1.setdata(5, 7);
    z5 = x1 + x2;
    cout << z1 << z2 << z3 << z4 << z5;
    return 0;
}
