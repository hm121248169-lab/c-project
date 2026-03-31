#include<bits/stdc++.h>
using namespace std;

class teacher{
private:
    string jobNO;
    string Name;
    double base_pay;
    double allowance;
    double insurance;
    double total_salary;
    double actual_salary;

public:
    teacher(string no, string name):jobNO(no),Name(name){
        base_pay = 0;
        allowance = 0;
        insurance = 0;
        total_salary = 0;
        actual_salary = 0;
    }
    
    teacher(string no, string name, double bp, double all, double ins):jobNO(no),Name(name){
        base_pay = bp;
        allowance = all;
        insurance = ins;
        total_salary = 0;
        actual_salary = 0;
    }
    
    void salary(){
        total_salary = base_pay + allowance;
        actual_salary = total_salary - insurance;
    }
    
    void display(){
        cout<<fixed<<setprecision(2);
        cout<<jobNO<<" "<<Name<<" "<<base_pay<<" "<<allowance<<" "<<insurance<<" "<<total_salary<<" "<<actual_salary<<endl;
    }
    
    void input(){
        cin>>base_pay>>allowance>>insurance;
    }
};

int main(){
    teacher t1("111", "Mary"),t2("222","Alex",4256.78,1234.56, 895.17);
    
    t1.input();
    t2.input();
    
    t1.salary();
    t2.salary();
    
    t1.display();
    t2.display();
    
    return 0;
}