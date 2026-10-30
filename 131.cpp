#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *p = new Node;
        p->data = val;
        p->prev = NULL;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    
    tail->next = head;
    head->prev = tail;

   
    int del_val = head->data;
    Node *p_del = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    delete p_del;


    Node *cur = head;
    bool find_all_small = false;
    while(cur->data < del_val)
    {
        cur = cur->next;
        if(cur == head)
        {
            find_all_small = true;
            break;
        }
    }

    Node *ins = new Node;
    ins->data = del_val;
    if(find_all_small)
    {
       
        ins->prev = head->prev;
        ins->next = head;
        head->prev->next = ins;
        head->prev = ins;
    }
    else
    {
        
        ins->prev = cur->prev;
        ins->next = cur;
        cur->prev->next = ins;
        cur->prev = ins;
        if(cur == head)
        {
            head = ins;
        }
    }

    Node *tmp = head;
    do
    {
        cout << tmp->data;
        if(tmp->next != head) cout << " ";
        tmp = tmp->next;
    }while(tmp != head);
    cout << endl;

    return 0;
}
