#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n = 0;
    char ch;

    while (cin >> a[n])
    {
        n++;
        cin >> ch;
    }

    int res[100];
    int k = 0;
    // 先放所有奇数（保持原顺序）
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
        {
            res[k++] = a[i];
        }
    }
    // 再放所有偶数（保持原顺序）
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            res[k++] = a[i];
        }
    }

    // 统一输出，逗号只在数字之间，绝对不会多出开头逗号
    for(int i = 0; i < k; i++)
    {
        if(i != 0)
            cout << ",";
        cout << res[i];
    }

    return 0;
}
