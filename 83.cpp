#include<bits/stdc++.h>
using namespace std;

template<typename T>
T power(T x, int y) {
    if (y == 0) {
        return T(1);
    }
    
    T result = 1;
    bool negative = false;
    
    if (y < 0) {
        negative = true;
        y = -y;
    }
    
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    
    if (negative) {
        return T(1) / result;
    }
    
    return result;
}

int main() {
    int x1, y1;
    double x2;
    int y2;
    
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
    cout << power(x1, y1) << endl;
    cout << fixed << setprecision(2) << power(x2, y2) << endl;
    
    return 0;
}