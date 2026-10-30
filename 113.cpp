#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[100];
    int i=0;
    cin>>a[i];
    while(a[i]!='#'){
        i++;
        cin>>a[i];
    }
    int len=i;

    int left=0;
    int right=len-1;
    int flag=1;
    while(left<right){
        if(a[left]!=a[right]){
            flag=0;
            break;
        }
        left++;
        right--;
    }
    if(flag==1){
        cout<<len<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}