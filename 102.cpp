#include<bits/stdc++.h>
using namespace std;

class student{
private:
    string num;
    string name;
    int score;
public:
    
    student(){
        cin>>num>>name>>score;
    }
    void display(){
        cout<<num<<" "<<name<<" "<<score<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    student *p=new student[n];
    for(int i=0;i<n;i++){
        p[i].display();
    }
    return 0;
}