#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    int len=s1.length();
    int i;
    int flag=0;
    char max=s1[0];
    for(i=0;i<len;i++){
        if(s1[i]>max){
            max=s1[i];
            flag=i;
        }
    }

    string s2="";
    for(i=0;i<flag;i++){
        s2+=s1[i];
    }
    s2=s2+"***";
    for(i=flag+1;i<len;i++){
        s2+=s1[i];
    }
    cout<<s2;
    return 0;

}