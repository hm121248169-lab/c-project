#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void cry() = 0;
    virtual ~Animal() {}
};

class Mouse : public Animal {
public:
    Mouse(string n) : Animal(n) {}
    void cry() override {
        cout << "I am a mouse, my name is " << name << ", zhizhi." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void cry() override {
        cout << "I am a cat, my name is " << name << ", miaomiao." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void cry() override {
        cout << "I am a dog, my name is " << name << ", wangwang." << endl;
    }
};

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
}