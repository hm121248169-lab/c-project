#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int result = 0;
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
            result += sum;
            pq.push(sum);
            
        }
    cout << result << endl;
    
    return 0;
}
