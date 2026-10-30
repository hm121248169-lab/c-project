#include <iostream>
#include <string>
using namespace std;

//基类 person，含有纯虚函数 eat，变成抽象类
class person
{
protected:
    string name;
public:
    person(string n) : name(n)
    {

    }
    //纯虚函数
    virtual void eat() = 0;
};

//学生类，公有继承person
class student : public person
{
public:
    student(string n) : person(n)
    {

    }
    void eat()
    {
        cout << "I am a student, my name is " << name << ", I want to have lunch at mess hall!" << endl;
    }
};

//老师类
class teacher : public person
{
public:
    teacher(string n) : person(n)
    {

    }
    void eat()
    {
        cout << "I am a teacher, my name is " << name << ", I want to eat potato in CHUANWEI restaurant!" << endl;
    }
};

//老板类
class boss : public person
{
public:
    boss(string n) : person(n)
    {

    }
    void eat()
    {
        cout << "I am a boss, my name is " << name << ", I want to eat fish in GAODIJIE restaurant!" << endl;
    }
};

//题目给定的main函数原样保留
int main()
{
    int choice;
    person *p = NULL;
    string nameValue;
    cin>>choice;
    cin>>nameValue;
    if(choice==1)
        p=new student(nameValue);
    else
        if(choice==2)
            p=new teacher(nameValue);
        else
            if(choice==3)
                p=new boss(nameValue);
    p->eat();
    if(p!=NULL) delete p;
    return 0;
}
