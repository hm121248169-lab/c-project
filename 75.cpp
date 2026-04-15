#include<iostream>
using namespace std;

class point {
private:
    int x;
    int y;

public:
    point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    point operator+(const point& other) const {
        return point(x + other.x, y + other.y);
    }

    point operator-(const point& other) const {
        return point(x - other.x, y - other.y);
    }

    bool operator==(const point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const point& other) const {
        return (x != other.x || y != other.y);
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }

    void set_x(int x) {
        this->x = x;
    }

    void set_y(int y) {
        this->y = y;
    }
};

istream& operator>>(istream& in, point& p) {
    int x, y;
    in >> x >> y;
    p.set_x(x);
    p.set_y(y);
    return in;
}

ostream& operator<<(ostream& out, const point& p) {
    out << "(" << p.get_x() << "," << p.get_y() << ")" << endl;
    return out;
}

int main()
{
    point  x, y, z1, z2;
    cin >> x >> y;
    z1 = x + y;
    z2 = x - y;
    cout << z1 << z2;

    if (x == y)   cout << "x==y" << endl;
    else   cout << "x!=y" << endl;

    if (z1 != z2)   cout << "z1!=z2" << endl;
    else   cout << "z1==z2" << endl;
    return 0;
}