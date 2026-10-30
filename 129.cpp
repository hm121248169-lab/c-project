#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> cnt;

    string s;
    
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s]++;
    }


    for(int i = 0; i < m; i++)
    {
        cin >> s;
        if(cnt.find(s) != cnt.end())
        {
            cout << cnt[s] << '\n';
        }
        else
        {
            cout << "None\n";
        }
    }
    return 0;
}
