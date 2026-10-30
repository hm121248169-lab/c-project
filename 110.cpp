#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        long long num[n];
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        long long m;
        cin>>m;
        int flag=0;
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                for(int c=0;c<n;c++){
                    for(int d=0;d<n;d++){
                        if(num[a]+num[b]+num[c]+num[d]==m){
                            flag=1;
                            
                        }
                    }
                }
            }
        }
        if(flag==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}