#include<bits/stdc++.h>
using namespace std;

class List
{
private:
    int data[20];
    int length;
public:
  
    List()
    {
        length = 0;
    }

  
    bool insertTail(int e)
    {
       
        data[length++] = e;
        return true;
    }


    int getLength()
    {
        return length;
    }


    bool getElem(int i, int &e)
    {
        e = data[i];
        return true;
    }

    void reverse(int l, int r)
    {
        while(l < r)
        {
            int temp = data[l];
            data[l] = data[r];
            data[r] = temp;
            l++;
            r--;
        }
    }


    void swapSub(int m)
    {
        int n = length;
        reverse(0, m-1);     
        reverse(m, n-1);     
        reverse(0, n-1);    
    }
};

int main()
{
    int n;
    cin >> n;
    List L;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        L.insertTail(x);
    }
    int m;
    cin >> m;
    L.swapSub(m);  

    cout << "{ ";
    int e;
    for(int i=0; i<L.getLength(); i++)
    {
        L.getElem(i, e);
        cout << e << " ";
    }
    cout << "}" << endl;
    return 0;
}
