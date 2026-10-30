#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Array{
    private:
        T *data;
        int size;
    public:
        Array(int n) {
            size=n;
            data=new T[size];
        }       
        ~Array() {
            delete[] data;
        }
        int sizeOfArray() {
            return size;
        }
        void input() {
            for(int i=0;i<size;i++) {
                cin>>data[i];
            }
        }
        void display() {
            int i;
            for(i=0;i<size;i++) {
                if(i>0) cout<<" ";
                cout<<data[i];
            }
            cout<<endl;
        }
};
int main()
{
    int choice, n;
    cin >> choice;
    cin >> n;
    if (choice == 1)
    {
        Array<int> arr(n);
        arr.input();
        arr.display();
    }
    else if (choice == 2)
    {
        Array<double> arr(n);
        arr.input();
        arr.display();
    }
    else if (choice == 3)
    {
        Array<char> arr(n);
        arr.input();
        arr.display();
    }
    return 0;
}