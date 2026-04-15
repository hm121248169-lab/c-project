#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        string stuNum;
        string stuName;
        int math;
        int english;
        int program;
        int total;

    public:  
        student(string stuNum, string stuName):stuNum(stuNum),stuName(stuName),math(0),english(0),program(0),total(0) {}
        student(string stuNum, string stuName, int math, int english, int program):stuNum(stuNum),stuName(stuName),math(math),english(english),program(program),total(0) {}

        void sumfun(){
            total = math + english + program;
        }

        void print(){
            cout<<stuNum<<" "<<stuName<<" "<<math<<" "<<english<<" "<<program<<" "<<total<<endl;
        }

        void input(){
            cin>>math>>english>>program;
            sumfun();
        }



    };

    int main(){
        student st1("111","John"), st2("222","Mike",67,89,92);
        st1.input();
        st2.sumfun();
        st1.print();
        st2.print();
        return 0;
    }