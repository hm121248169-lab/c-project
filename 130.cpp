#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_set<int> s;
    s.reserve(100);
    int x;
    bool first = true;
    for(int i=0;i<n;i++){
        cin>>x;
        if(s.find(x)==s.end()){
            s.insert(x);
            if(!first){
                cout<<" ";
                
            }
            cout<<x;
            first = false;
            
        }
    }
}