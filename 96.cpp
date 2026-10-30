#include<bits/stdc++.h>
using namespace std;

class vehicle{
protected:
    int num;
    string name;
public:
    vehicle(int n,string s){
        num=n;
        name=s;
    }
    void display(){
        cout<<"vehicleID="<<num<<" vehicleName="<<name<<endl;
    }
};
class bike:public vehicle{
private:
    int weight;
public:
    bike(int n,string s,int w):vehicle(n,s){
        weight=w;
    }
    void display(){
        cout<<"vehicleID="<<num<<" vehicleName="<<name<<" weight="<<weight<<endl;
    }    
        
};

int main()
{
 int ID;
 string name;
 int weight;

 cin>>ID>>name;

 class vehicle vehicle1(ID,name);
 vehicle1.display();
 cout<<endl;
 cin>>ID>>name>>weight;
 class bike bike1(ID,name,weight);
 bike1.display();
 cout<<endl;

    return 0;
}