#include<bits/stdc++.h>
using namespace std;

template<typename T>
T power(T x,T y){
    int i;
    T temp=1;
    for(i=0;i<y;i++){
        temp=temp*x;
    }
    return temp;
}

int main(){
    int a, n1;
    cin >> a >> n1;
    double b, n2;
    cin >> b >> n2;
    
    cout << power(a, n1) << endl;
    cout << power(b, n2) << endl;
    return 0;
}
