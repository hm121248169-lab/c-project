#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        string type;
        cin >> n >> type;

        if(type == "FIFO")
        {
            queue<int> q;
            string op;
            for(int i = 0; i < n; i++)
            {
                cin >> op;
                if(op == "IN")
                {
                    int m;
                    cin >> m;
                    q.push(m);
                }
                else if(op == "OUT")
                {
                    if(q.empty())
                    {
                        cout << "None" << endl;
                    }
                    else
                    {
                        cout << q.front() << endl;
                        q.pop();
                    }
                }
            }
        }
        else if(type == "FILO")
        {
            stack<int> st;
            string op;
            for(int i = 0; i < n; i++)
            {
                cin >> op;
                if(op == "IN")
                {
                    int m;
                    cin >> m;
                    st.push(m);
                }
                else if(op == "OUT")
                {
                    if(st.empty())
                    {
                        cout << "None" << endl;
                    }
                    else
                    {
                        cout << st.top() << endl;
                        st.pop();
                    }
                }
            }
        }
    }
    return 0;
}
