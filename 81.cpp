#include <iostream>
#include <string>
using namespace std;

class goods {
protected:
    int goodsID;
    string goodsName;
public:
    goods() {
        cin >> goodsID >> goodsName;
    }
    void display() {
        cout << "goodsID=" << goodsID << " goodsName=" << goodsName;
    }
};

class foods : public goods {
private:
    int days;
public:
    foods() {
        cin >> days;
    }
    void display() {
        cout << "goodsID=" << goodsID << " goodsName=" << goodsName << " days=" << days;
    }
};

int main()
{
    class goods goods1;
    goods1.display();
    cout<<endl;
    class foods foods1;
    foods1.display();
    cout<<endl;
    return 0;
}