#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int *a = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
    }
    
    cout << "a[" << n << "]={";
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << *(a + i);
    }
    cout << "}" << endl;
    
    for (int i = 0; i < n; i++) {
        if (*(a + i) < 0) {
            *(a + i) = 0;
        }
    }
    
    cout << "a[" << n << "]={";
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << *(a + i);
    }
    cout << "}" << endl;
    
    delete[] a;
    
    return 0;
}