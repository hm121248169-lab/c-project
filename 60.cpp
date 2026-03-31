#include<bits/stdc++.h>
using namespace std;

class book{
    private:
        string ISBN;
        string bookname;
        string authur;
        double price;
    public:
        book(){
            ISBN="";
            bookname="";
            authur="";
            price=0.0;
        }  
    void input(){
        cin>>ISBN>>bookname>>authur>>price;
    }
    void output(){
        cout<<ISBN<<" "<<bookname<<" "<<authur<<" "<<price<<endl;
    }
    double getdata(){
        return price;
    }
    
};


int main(){
    book b[3];

    int i;
    for(i=0;i<3;i++){
        b[i].input();
    }
    for(i=0;i<3;i++){
        b[i].output();
    }
    double sum=0;
    for(i=0;i<3;i++){
        sum+=b[i].getdata();
    }

    cout<<sum<<endl;
    return 0;

}