#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<string> s;
    string fruit;
    for(int i=0;i<n;i++){
        cin>>fruit;
        s.insert(fruit);
    }
    for(auto x:s){
        cout<<x<<endl;
    }
    return 0;
}