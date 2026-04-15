#include<bits/stdc++.h>
using namespace std;


class matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    matrix() {
        rows = 0;
        cols = 0;
        data = NULL;
    }

    matrix(int m, int n) {
        rows = m;
        cols = n;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    matrix(const matrix& other) {
        rows = other.rows;
        cols = other.cols;
        if (other.data != NULL) {
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        } else {
            data = NULL;
        }
    }

    ~matrix() {
        if (data != NULL) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    friend istream& operator>>(istream& is, matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                is >> mat.data[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                if (j > 0) {
                    os << " ";
                }
                os << mat.data[i][j];
            }
            os << endl;
        }
        return os;
    }

    matrix operator+(const matrix& other) const {
        matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    matrix operator-(const matrix& other) const {
        matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    matrix& operator=(const matrix& other) {
        if (this != &other) {
            if (data != NULL) {
                for (int i = 0; i < rows; i++) {
                    delete[] data[i];
                }
                delete[] data;
            }

            rows = other.rows;
            cols = other.cols;
            if (other.data != NULL) {
                data = new int*[rows];
                for (int i = 0; i < rows; i++) {
                    data[i] = new int[cols];
                    for (int j = 0; j < cols; j++) {
                        data[i][j] = other.data[i][j];
                    }
                }
            } else {
                data = NULL;
            }
        }
        return *this;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    matrix mat1(m, n), mat2(m, n), mat3, mat4;
    cin >> mat1 >> mat2;
    mat3 = mat1 + mat2;
    cout << mat3;
    mat4 = mat1 - mat2;
    cout << mat4;
    return 0;
}