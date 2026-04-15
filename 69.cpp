#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;
    int *a = new int[n];
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<"a["<<n<<"]={";
    for(i=0;i<n;i++){
        
        cout<<a[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<"}\n";
    cout<<"sum="<<sum<<"\n";
    delete[] a;
    return 0;

}