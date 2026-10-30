#include <iostream>
#include <string>
using namespace std;

//父类
class Worker
{
protected:
    string name;
public:
    Worker(string n):name(n){}
    virtual void printInfo() = 0; //纯虚函数，Worker变成抽象类
    virtual ~Worker(){} //虚析构函数，delete基类指针正确释放子类空间
};

//固定工资员工
class AWorker:public Worker
{
private:
    int salary;
public:
    AWorker(string n,int s):Worker(n),salary(s){}
    void printInfo()
    {
        cout << name << " " << salary << endl;
    }
};

//计件工人
class BWorker:public Worker
{
private:
    int num;
    int single_sal;
public:
    BWorker(string n,int nu,int si):Worker(n),num(nu),single_sal(si){}
    void printInfo()
    {
        int money = num * single_sal;
        cout << name << " " << money << endl;
    }
};

//班组长
class CWorker:public Worker
{
private:
    int salary;
    int bonus;
public:
    CWorker(string n,int s,int b):Worker(n),salary(s),bonus(b){}
    void printInfo()
    {
        int money = salary + bonus;
        cout << name << " " << money << endl;
    }
};

int main()
{
    Worker* w = NULL;
    string name;
    int salary;
    cin >> name >> salary;
    w = new AWorker(name, salary);
    w->printInfo();
    delete w;

    int num, single_sal; // 数量，单件工资
    cin >> name >> num >> single_sal;
    w = new BWorker(name, num, single_sal);
    w->printInfo();
    delete w;
    
    int bonus;
    cin >> name >> salary >> bonus; // 工资、奖金
    w = new CWorker(name, salary, bonus);
    w->printInfo();
    delete w;
    return 0;
}
