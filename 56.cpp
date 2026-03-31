#include<bits/stdc++.h>
using namespace std;

class rectangle{
private:
    double length;
    double width;

public:
    rectangle():length(0.0),width(0.0){}
    rectangle(double l,double w):length(l),width(w){}

    void assign(double a,double b){ 
        if(a>b){
            length=a;
            width=b;
        }
        else{
            length=b;
            width=a;
        }
    }
    double circumference(){
        return 2*(length+width);    
    }
    double area(){
        return length*width;
    }
    void show(){
        cout<<fixed<<setprecision(2);
        cout<<length<<","<<width<<","<<circumference()<<","<<area()<<endl;
    }
};

int main(){
    rectangle c1,c2(2.0,1.0),c3;
    double x,y;

    cin>>x>>y;
    c3.assign(x,y);
    c1.show();
    c2.show();
    c3.show();
    return 0;
}