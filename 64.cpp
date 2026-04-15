#include<bits/stdc++.h>
using namespace std;

class cube{
    private:
        int length;
        int width;
        int height;
    public:
        cube(): length(1), width(1), height(1) {}
        cube(int l): length(l), width(1), height(1) {}
        cube(int l,int w):length(l), width(w), height(1) {}
        cube(int l,int w,int h):length(l), width(w), height(h) {}

        void input(){
            cin>>length>>width>>height;
        }

        int volume(){
            return length*width*height;
        }

        int area(){
            return 2*(length*width+length*height+width*height);
        }

        void display(){
            cout<<length<<","<<width<<","<<height<<","<<volume()<<","<<area()<<endl;
        }
};

int main(){
    cube c1,c2,c3(2),c4(2,3),c5(2,3,4);
    c1.input();
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
    return 0;
}