#include<bits/stdc++.h>
using namespace std;

class settype {
public:
    settype();                      // 构造函数，默认空集
    settype(const settype& B);      // 拷贝构造函数
    ~settype();                     // 析构函数

    void getdata(int* a, int& num) const; // 读值函数
    void setdata(int* a, int num);        // 设值函数
    int get_n() const;              // 获取集合当前元素数目

    settype operator+(settype B);   // 重载运算符+，实现集合并运算
    settype operator*(settype B);   // 重载运算符*，实现集合交运算
    settype operator-(settype B);   // 重载运算符-，实现集合差运算
    settype operator=(settype B);   // 重载运算符=

    // 声明友元函数以支持 cin >> 和 cout <<
    friend istream& operator>>(istream& in, settype& s);
    friend ostream& operator<<(ostream& out, const settype& s);

private:
    int* set;   // 数组指针
    int n;      // 元素的个数
    
    // 辅助函数：判断元素是否存在于集合中
    bool contains(int val) const;
    // 辅助函数：添加元素到集合（如果不重复）
    void addIfNotExists(int val);
};

settype::settype()

{
  n=0;
  set=NULL;

}

settype::settype(const settype& B) {
    n = B.n;
    if (n > 0) {
        set = new int[n];
        for (int i = 0; i < n; i++) {
            set[i] = B.set[i];
        }
    } else {
        set = NULL;
    }
}

settype::~settype() {
    if (set != NULL) {
        delete[] set;
        set = NULL;
    }
    n = 0;
}


void settype::getdata(int* a, int& num) const {
    num = n;
    if (n > 0 && a != NULL) {
        for (int i = 0; i < n; i++) {
            a[i] = set[i];
        }
    }
}

// 设值函数
void settype::setdata(int* a, int num) {
    // 先释放原有内存
    if (set != NULL) {
        delete[] set;
    }
    
    n = 0;
    set = NULL;

    if (num > 0 && a != NULL) {
        // 为了保持集合性质（无重复），我们逐个添加
        for (int i = 0; i < num; i++) {
            addIfNotExists(a[i]);
        }
    }
}

int settype::get_n() const {
    return n;
}

// 辅助函数：判断元素是否存在
bool settype::contains(int val) const {
    for (int i = 0; i < n; i++) {
        if (set[i] == val) {
            return true;
        }
    }
    return false;
}

// 辅助函数：添加不重复元素
void settype::addIfNotExists(int val) {
    if (!contains(val)) {
        int* newSet = new int[n + 1];
        for (int i = 0; i < n; i++) {
            newSet[i] = set[i];
        }
        newSet[n] = val;
        
        if (set != NULL) {
            delete[] set;
        }
        set = newSet;
        n++;
    }
}

// 重载赋值运算符
settype settype::operator=(settype B) {
    // 使用拷贝交换惯用法或手动深拷贝
    // 这里为了简单直观，手动实现深拷贝逻辑
    
    if (this == &B) {
        return *this;
    }

    // 释放旧内存
    if (set != NULL) {
        delete[] set;
    }

    // 复制新数据
    n = B.n;
    if (n > 0) {
        set = new int[n];
        for (int i = 0; i < n; i++) {
            set[i] = B.set[i];
        }
    } else {
        set = NULL;
    }
    
    return *this;
}

// 重载 + (并集)
settype settype::operator+(settype B) {
    settype result;
    // 先把 A 的所有元素加入结果
    for (int i = 0; i < this->n; i++) {
        result.addIfNotExists(this->set[i]);
    }
    // 再把 B 的所有元素加入结果（addIfNotExists 会自动去重）
    for (int i = 0; i < B.n; i++) {
        result.addIfNotExists(B.set[i]);
    }
    return result;
}

// 重载 * (交集)
settype settype::operator*(settype B) {
    settype result;
    // 遍历 A，如果元素也在 B 中，则加入结果
    for (int i = 0; i < this->n; i++) {
        if (B.contains(this->set[i])) {
            result.addIfNotExists(this->set[i]);
        }
    }
    return result;
}

// 重载 - (差集 A-B)
settype settype::operator-(settype B) {
    settype result;
    // 遍历 A，如果元素不在 B 中，则加入结果
    for (int i = 0; i < this->n; i++) {
        if (!B.contains(this->set[i])) {
            result.addIfNotExists(this->set[i]);
        }
    }
    return result;
}

// --- 友元函数实现 (输入输出流重载) ---

istream& operator>>(istream& in, settype& s) {
    int num;
    in >> num;
    
    if (num > 0) {
        int* temp = new int[num];
        for (int i = 0; i < num; i++) {
            in >> temp[i];
        }
        s.setdata(temp, num);
        delete[] temp;
    } else {
        s.setdata(NULL, 0);
    }
    return in;
}

ostream& operator<<(ostream& out, const settype& s) {
    out << "{";
    for (int i = 0; i < s.n; i++) {
        out << s.set[i];
        if (i < s.n - 1) {
            out << ",";
        }
    }
    out << "}" << endl;
    return out;
}


int main(int argc, char* argv[])

{

settype A, B, C;    

  cin>>A>>B;
cout<<"A="<<A;

  cout<<"B="<<B;

C=A+B;

  cout<<"A+B="<<C;

C=A*B;

  cout<<"A*B="<<C;

C=A-B;

  cout<<"A-B="<<C;

  return 0;

}