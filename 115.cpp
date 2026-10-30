#include<bits/stdc++.h>
using namespace std;

class List
{
private:
    int* data;
    int length;    
    int maxSize;
public:
   
    List(int n = 100)
    {
        maxSize = n;
        data = new int[maxSize];
        length = 0;
    }
    ~List()
    {
        delete[] data;
    }

    int getLength()
    {
        return length;
    }

    bool getElem(int i, int &e)
    {
        if(i <0 || i >= length) return false;
        e = data[i];
        return true;
    }

   
    bool deleteElem(int i)
    {
        if(i <0 || i >= length) return false;
        for(int j = i; j < length-1; j++)
        {
            data[j] = data[j+1];
        }
        length--;
        return true;
    }

    bool insertTail(int e)
    {
        if(length >= maxSize) return false;
        data[length++] = e;
        return true;
    }
    
};


bool DelSt(List &L, int s, int t)
{
    if(s > t) return false;
    int len = L.getLength();
    int i = 0;
    while(i < L.getLength())
    {
        int val;
        L.getElem(i, val);
        if(val >= s && val <= t)
        {
           
            L.deleteElem(i);
            
        }
        else
        {
            i++;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    List L(100);
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        L.insertTail(x);
    }
    int s, t;
    cin >> s >> t;

    if(s > t)
    {
        cout << "s or t error!" << endl;
        return 0;
    }

    bool ok = DelSt(L, s, t);
    if(!ok)
    {
        cout << "s or t error!" << endl;
        return 0;
    }

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
