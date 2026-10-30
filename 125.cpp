#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int score;
};

const int N=1000;
Student stu[N];
int cnt=0;

int find(string s){
    for(int i=0;i<cnt;i++){
        if(stu[i].name==s) return i;
    }
    return -1;
}

int main(){
    int n,m;
    cin>> n >> m;
    for(int i=0;i<n;i++){
        string name;
        int sc;
        cin >> name >> sc;
        int pos = find(name);
        if(pos!=-1){
            stu[pos].score=sc;
            
        }
        else{
            stu[cnt].name=name;
            stu[cnt].score=sc;
            cnt++;
        }
    }
    for(int i=0;i<m;i++){
        string q;
        cin>>q;
        int p = find(q);
        if(p!=-1){
            cout << stu[p].score << endl;
        }
        else{
            cout << "None" << endl;
        }
    }
    return 0;
}