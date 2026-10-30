#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
while(b){
    long long t = a % b;
    a = b;
    b = t;

    }
    return a;
}

int main(){
    long long m,n;
   
    while(cin >> m >> n){
        long long r1=gcd(m,n);
        long long r2=m/r1*n;
        cout <<r1<<" "<<r2<<endl;
    }
    return 0;

}