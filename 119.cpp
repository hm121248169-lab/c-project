#include<iostream>
#include<queue>
using namespace std;

const int MAXN=1005;
int K[MAXN];
bool vis[MAXN];     
int n,A,B;

struct Node{
    int floor;
    int step;
};

int main(){
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++){
        cin>>K[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }

    queue<Node> q;
    q.push({A,0});
    vis[A]=true;
    while(!q.empty()){
        Node cur=q.front();
        q.pop();
        if(cur.floor==B){
            cout<<cur.step<<endl;
            return 0;
        }
        int k=K[cur.floor];
        int up=cur.floor+k;
        if(up<=n && !vis[up]){
            vis[up]=true;
            q.push({up,cur.step+1});
        }
        int down=cur.floor-k;
        if(down>=1 && !vis[down]){
            vis[down]=true;
            q.push({down,cur.step+1});
        }
    }
    cout<<-1<<endl;
    return 0;
}