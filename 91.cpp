#include<bits/stdc++.h>
using namespace std;


int main(){
    string countries[10] = {"Australia", "Belgium", "China", "Denmark", "England", 
                            "France", "Greece", "Ireland", "Scotland", "Wales"};
    string capitals[10] = {"Canberra", "Brussels", "Beijing", "Copenhagen", "London",
                           "Paris", "Athens", "Dublin", "Edinburgh", "Cardiff"};
    int n;
    cin>>n;

    int i;
    for(i=0;i<n;i++){
        string country;
        cin>>country;

        int find=0;
        for(int j=0;j<10;j++){
            if(country==countries[j]){
                cout<<capitals[j]<<endl;
                find=1;
                break;
            }
        }
        if(!find){
            cout<<"Not found!"<<endl;
        }
    }
    return 0;

}