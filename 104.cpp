#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        int pos = s2.find(s1[i]);
        if (pos == -1) //找不到该字符，不是anagrams
        {
            cout << "no" << endl;
            return 0;
        }
        s2.erase(pos, 1); //找到就删掉这个字符
    }
    if (s2.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
