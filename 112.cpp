#include<bits/stdc++.h>
using namespace std;

class List{
private:
    int data[100];
    int length;
    
public:
    int get(int i){
        return data[i];
    }

    void set(int i, int value){
        data[i] = value;
    }

    int getlength(){
        return length;
    }

    void setlength(int n){
        length = n;
    }

    void display(){
        cout<<"{ ";
        for(int i=0; i<length; i++){
            cout<<data[i]<<" ";
        }
        cout<<"}"<<endl;
    }
};

void reverse(List &l){
    int n = l.getlength();
    for(int i=0; i<n/2; i++){
        int temp = l.get(i);
        l.set(i, l.get(n-i-1));
        l.set(n-i-1, temp);
    }
}

int main(){
    int n;
    cin>>n;
    List l;
    l.setlength(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        l.set(i, x);
    }
    reverse(l);
    l.display();
    return 0;
}