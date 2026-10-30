#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* creat(){
    Node* h = new Node;
    h->next = NULL;
    Node* t = h;
    int n;
    while(cin >> n && n != -1){
        Node* p = new Node;
        p->data = n;
        p->next = NULL;
        t->next = p;
        t = p;
    }
    return h;
}

int count(Node* h,int x){
    int c=0;
    Node* p = h->next;
    for(;p;p=p->next){
        if(p->data==x) c++;
    }
    return c;
}

void print(Node* h){
    Node* p = h->next;
    for(;p;p=p->next){
        cout << p->data;
        if(p->next) cout << "-->";
    }
    cout << endl;
}

int main(){
    Node* l = creat();
    int x;
    cin >> x;
    print(l);
    cout << count(l,x);
    return 0;
}