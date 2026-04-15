#include<bits/stdc++.h>
using namespace std;

class fraction{
    private:
        int zi;
        int mu;
    
    public:
        fraction(): zi(0), mu(1) {}
        
        fraction(int z, int m): zi(z), mu(m) {}

        void input(){
            cin>>zi>>mu;
            simplify();
        }
        void simplify(){
            if(mu == 0){
                return; 
            }
            
            
            if(mu < 0){
                zi = -zi;
                mu = -mu;
            }
            
            
            int gcd_val = gcd(abs(zi), abs(mu));
            zi /= gcd_val;
            mu /= gcd_val;
        }
        void output(){
            simplify();
            if(zi == 0){
                cout<<0<<endl;
            } else if(mu==1){
                cout<<zi<<endl;
            } else {
                cout<<zi<<"/"<<mu<<endl;
            }

        }
    private:
        int gcd(int a, int b){
            if(b == 0){
                return a;
            }
            return gcd(b, a % b);
        }    
};

int main(){
    int a, b;
    cin>>a>>b;
    fraction x1, x2(a,b);
    x1.output();
    x2.output();
    x2.input();
    x2.output();
    return 0;
}