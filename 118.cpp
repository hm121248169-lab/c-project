#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;

    for(int i=0;i<n;i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(op==2){
            if(q.empty()){
                cout<<"ERR_CANNOT_POP"<<endl;
            }
            else{
                q.pop();
            }
        }
        else if(op==3){
            if(q.empty()){
                cout<<"ERR_CANNOT_QUERY"<<endl;
            }
            else{
                cout<<q.front()<<endl;
            }
        }
        else if(op==4){
            cout<<q.size()<<endl;
        }
    }
    return 0;
}