#include<iostream>
#include<iomanip>
using namespace std;

class complex{
private:
    double real;
    double imaginary;
public:
    complex(){
        real=0;
        imaginary=0;
    }
    complex(double r,double i){
        real=r;
        imaginary=i;
    }
    complex operator+(complex c2){
        complex c1=*this;
        complex res(c1.real+c2.real,c1.imaginary+c2.imaginary);
        return res;
    }

    complex operator-(complex c2){
        complex c1=*this;
        complex res(c1.real-c2.real,c1.imaginary-c2.imaginary);
        return res;
    }
    
    bool operator==(complex c2){ 
        complex c1=*this;
        if(c1.real==c2.real && c1.imaginary==c2.imaginary)
            return true;
        else
            return false;
    }

    bool operator!=(complex c2){ 
        complex c1=*this;
        if(c1.real==c2.real && c1.imaginary==c2.imaginary)
            return false;
        else
            return true;
    }

    bool operator<(complex c2){ 
        complex c1=*this;
        double a=c1.real*c1.real+c1.imaginary*c1.imaginary;
        double b=c2.real*c2.real+c2.imaginary*c2.imaginary;
        if (a<b)
            return true;
        else
            return false;
    }

    bool operator>(complex c2){ 
        complex c1=*this;
        double a=c1.real*c1.real+c1.imaginary*c1.imaginary;
        double b=c2.real*c2.real+c2.imaginary*c2.imaginary;
        if (a>b)
            return true;
        else
            return false;
       
    }
    double getReal(){
        return real;
    }
    double getImag(){
        return imaginary;
    }

    void setReal(double r){
        real=r;
        
    }

    void setImag(double &i){
        
        imaginary=i;
    }
};

istream &operator>>(istream &is,complex &c){
    double r,i;
    char ch1,ch2;
    is>>r>>ch1>>i>>ch2;
    if(ch1=='-'){
        i=-i;
    }
    c.setReal(r);
    c.setImag(i);
    return is;
}

ostream &operator<<(ostream &os,complex &c){
    double r,i;
    r=c.getReal();
    i=c.getImag();
    os<<fixed<<setprecision(2);
    if(i>0){
    os<<r<<"+"<<i<<"i"<<endl;
    return os;
    }
    os<<r<<i<<"i"<<endl;
    return os;
}


int main(){


complex c1, c2, c3, c4, c5 ;

cin >> c1 >> c2 ;

c3 = c1 + c2 ;

c4 = c1 - c2 ;

if ( c3 != c4 )

{

if (c3 < c4)

{    cout << "c3 is less than c4" ;

     c5 = c4 - c3 ;

}

if ( c3 > c4 )

{    cout << "c3 is greater than c4" ;

     c5 = c3 - c4 ;

}

}

if ( c3 == c4 )

{   cout << "c3 and c4 are equal";

    c5 = c4 ;

}

cout<<endl;

cout << c5 ;

return 0;

}
