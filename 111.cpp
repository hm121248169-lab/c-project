#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return a<b?a:b;
}   
int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int a[n];
        int b[n];
        int re1[n];
        int re2[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=m-a[i];
        }
        for(int i=0;i<n;i++){
            re1[i]=min(a[i],b[i]);
            re2[i]=max(a[i],b[i]);
        }
        int max1=re1[0];
        int max2=re2[0];
        for(int i=0;i<n;i++){
            if(re1[i]>max1){
                max1=re1[i];
            }
            if(re2[i]>max2){
                max2=re2[i];
            }
        }
        cout << max1 << " " << max2 << endl;
    }
    return 0;
}