#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int x;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            pq.push(x);
        }

        while(pq.size() > 1)
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int sum = a + b;
            pq.push(sum);
        }
        cout << pq.top() << endl;
    }
    return 0;
}
