#include <iostream>
using namespace std;

class matrix
{
private:
    int m, n;
    int **p;  //指向指针的指针，二级指针
public:
    //构造函数：创建二维动态数组，行优先赋值
    matrix(int rows, int cols)
    {
        m = rows;
        n = cols;
        p = new int*[m];
        int count = 1;
        for(int i = 0; i < m; i++)
        {
            p[i] = new int[n];
            for(int j = 0; j < n; j++)
            {
                p[i][j] = count++;
            }
        }
    }

    //(1)返回行优先第i个元素，i从1开始
    int at(int i)
    {
        return i;
    }

    //(2)返回第i行j列元素，i,j从1开始
    int at(int i, int j)
    {
        return p[i - 1][j - 1];
    }

    //(3)求全部元素的和
    int sum()
    {
        int total = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                total += p[i][j];
            }
        }
        return total;
    }

    //析构函数释放动态开辟的内存
    ~matrix()
    {
        for(int i = 0; i < m; i++)
        {
            delete [] p[i];
        }
        delete [] p;
        p = nullptr;
    }
};

int main()
{
    int row, col, num, x, y;
    cin >> row >> col;
    matrix mat(row, col);
    cin >> num;
    cin >> x >> y;
    cout << mat.at(num) << endl;
    cout << mat.at(x, y) << endl;
    cout << mat.sum() << endl;
    return 0;
}
