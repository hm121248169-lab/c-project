#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int b[100];
    for(i=0;i<n;i++){
        int count=0;
        int j;
        for(j=0;j<i;j++){
            if(a[i]>a[j])
                count++;
        }
        b[i]=count;
    }
    for(i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    return 0;

}