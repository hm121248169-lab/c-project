#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
while(b){
    int t = a % b;
    a = b;
    b = t;

    }
    return a;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int re=n;
        for(int i=2;i<=m;i++){
            cin>>n;
            re = gcd(re, n);
        }
        cout << re << endl;
    }
    return 0;

}