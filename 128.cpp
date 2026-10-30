#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> cnt;

    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        cnt[s]++;
    }
    string ans;
    int max_count = 0;
    for(auto &p:cnt){
        if(p.second>max_count){
            max_count = p.second;
            ans = p.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}