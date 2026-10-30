#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    
    while (cin >> n && n != 0)
    {
        priority_queue<int> pq;
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            pq.push(num);
        }

        
        cout << pq.top();
        pq.pop();
        
        while (!pq.empty())
        {
            cout << " " << pq.top();
            pq.pop();
        }
        cout << endl;
    }
    return 0;
}
