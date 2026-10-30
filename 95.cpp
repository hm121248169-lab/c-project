#include<bits/stdc++.h>
using namespace std;

template<typename T>
class largest_element
{
private:
    T *data;
    int size;
public:
    largest_element(int n) {
        size = n;
        data = new T[size];
    }
    T largest(){
        T largest = data[0];
        int i;
        for(i=1;i<size;i++){
            if(data[i]>largest){
                largest=data[i];
            }
        }
        return largest;
    }
    ~largest_element(){
        delete[] data;
    }
    void input(){
        int i;
        for(i=0;i<size;i++){
            cin>>data[i];
        }
    }
    
    void display(){
        printf("%d", largest());
    }
};

int main(){
    int n1;
    cin >> n1;
    largest_element<int> obj1(n1);
    obj1.input();
    cout << obj1.largest() << endl;

    //第2组 double数组
    int n2;
    cin >> n2;
    largest_element<double> obj2(n2);
    obj2.input();
    cout << obj2.largest() << endl;

    //第3组 char数组
    int n3;
    cin >> n3;
    largest_element<char> obj3(n3);
    obj3.input();
    cout << obj3.largest() << endl;

    return 0;
}