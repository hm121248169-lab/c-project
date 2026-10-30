#include<bits/stdc++.h>
using namespace std;

class fraction{
private:
    int zi;
    int mu;
public:
    fraction(){
        zi=0;
        mu=1;
    }
    fraction(int z,int m){
        zi=z;
        mu=m;
    }
    int gcd(int a,int b){
        int temp;
        while(b!=0){
            temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    void reduce(){
        int g=gcd(zi,mu);
        zi/=g;
        mu/=g;
        if(mu<0){
            zi=-zi;
            mu=-mu;

        }
    }
    void common(fraction &f2){
        int g=gcd(mu,f2.mu);
        int lcm=mu/g*f2.mu;
        zi=zi*lcm/mu;
        mu=lcm;
        f2.zi=f2.zi*lcm/f2.mu;
        f2.mu=lcm;
    }

    fraction operator+(fraction f2){
        fraction fr=*this;
        fr.common(f2);
        fraction res(fr.zi+f2.zi,fr.mu);
        return res;
    }

    fraction operator-(fraction f2){
        fraction fr=*this;
        fr.common(f2);
        fraction res(fr.zi-f2.zi,fr.mu);
        return res;
    }
    
    fraction operator*(fraction f2){
        fraction fr=*this;
        fraction res(fr.zi*f2.zi,fr.mu*f2.mu);
        res.reduce();
        return res;
        
    }

    fraction operator/(fraction f2){
        fraction fr=*this;
        fraction res(fr.zi*f2.mu,fr.mu*f2.zi);
        res.reduce();
        return res;
    }

    void setdata(int z,int m){
        zi=z;
        mu=m;
    }

    void getdata(int &z,int &m){
        z=zi;
        m=mu;
    }
};



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
    else if(n==d)
    {
        os << 1 << endl;
    }
    else
    {
        os << n << "/" << d << endl;
    }
    return os;
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