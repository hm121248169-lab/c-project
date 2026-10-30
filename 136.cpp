#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(){
    Node* head=new Node;
    head->next=NULL;
    Node* tail=head;
    int val;
    while(cin>>val && val!=-1){
        Node* p=new Node;
        p->data=val;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    return head;
}

void printList(Node* head){
    Node* p=head->next;
    if(p==NULL) return;
    while(p!=NULL){
        cout<<p->data;
        if(p->next!=NULL){
            cout<<"-->";
        }
        p=p->next;
    }
    cout<<endl;
}

void Findmin(Node* head){
    if(head->next==NULL || head->next->next==NULL)
        return;
    Node* p=head;
    Node* preMin=head;
    while(p->next!=NULL){
        if(p->next->data<preMin->next->data){
            preMin=p;
        }
        p=p->next;
    }
    Node* minNode=preMin->next;
    preMin->next=minNode->next;
    minNode->next=head->next;
    head->next=minNode;

}

int main(){
    Node* head=createList();
    printList(head);
    Findmin(head);
    printList(head);
    return 0;
}