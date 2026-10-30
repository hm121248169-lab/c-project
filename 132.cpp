#include <iostream>
using namespace std;
struct Monkey{
    int id;
    Monkey *next;
};

int main()
{
    int n, m;
    cin >> n >> m;

    Monkey *head = NULL;
    Monkey *tail = NULL;

   
    for(int i = 1; i <= n; i++)
    {
        Monkey *p = new Monkey;
        p->id = i;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    tail->next = head; 

    Monkey *pre = tail;  
    Monkey *cur = head;

  
    while(cur->next != cur)
    {

        for(int i = 1; i < m; i++)
        {
            pre = cur;
            cur = cur->next;
        }
     
        pre->next = cur->next;
        delete cur;
        cur = pre->next;
    }
    cout << cur->id << endl;
    delete cur;
    return 0;
}
