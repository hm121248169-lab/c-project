#include<bits/stdc++.h>
using namespace std;

class matrix{
private:
    int **data;
    int rows;
    int cols;

public:
    matrix(int m, int n) {
        rows = m;
        cols = n;
        data = new int *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }

        int count = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = count++;
            }
        }
    }

    int at(int i) {
        int r = (i - 1) / cols;
        int c = (i - 1) % cols;
        return data[r][c];
    }

    int at(int i, int j) {
        return data[i - 1][j - 1];
    }

    int sum() {
        int total = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                total += data[i][j];
            }
        }
        return total;
    }

    ~matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
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