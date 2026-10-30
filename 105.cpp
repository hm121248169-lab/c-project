#include <iostream>
#include <string>
using namespace std;

//基类 Animal
class Animal
{
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    //虚函数，实现多态
    virtual void cry() {}
};

//老鼠子类
class Mouse : public Animal
{
public:
    Mouse(string n) : Animal(n) {}
    void cry()
    {
        cout << "I am a mouse, my name is " << name << ", zhizhi." << endl;
    }
};

//猫子类
class Cat : public Animal
{
public:
    Cat(string n) : Animal(n) {}
    void cry()
    {
        cout << "I am a cat, my name is " << name << ", miaomiao." << endl;
    }
};

//狗子子类
class Dog : public Animal
{
public:
    Dog(string n) : Animal(n) {}
    void cry()
    {
        cout << "I am a dog, my name is " << name << ", wangwang." << endl;
    }
};

//题目给定的主函数，完全原样照搬
int main()
{
    Animal *p;
    string name;
    cin >> name;
    Mouse m1(name);

    cin >> name;
    Cat c1(name);

    cin >> name;
    Dog d1(name);

    p = &m1;
    p->cry();

    p = &c1;
    p->cry();

    p = &d1;
    p->cry();
    return 0;
}
