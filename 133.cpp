#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

struct PolyNode {
    int coe;
    int exp;
    PolyNode* next;
    PolyNode(int c, int e) : coe(c), exp(e), next(NULL) {}
};

class PolyList {
public:
    PolyNode* head;
    PolyList() {
        head = new PolyNode(0, -1);
    }
    ~PolyList() {
        PolyNode* p = head;
        while(p != NULL) {
            PolyNode* q = p;
            p = p->next;
            delete q;
        }
    }
   
    void insert(int coe, int exp) {
        PolyNode* p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = new PolyNode(coe, exp);
    }
};

bool parsePoly(const string &s, PolyList &pl) {
    if(s.empty()) return false;
    string str = s;
   
    if(str[0] != '+' && str[0] != '-') {
        str = "+" + str;
    }
    int i = 0;
    int n = str.size();
    while(i < n) {
        char op = str[i];
        i++;
        string coeStr;
       
        while(i < n && isdigit(str[i])) {
            coeStr += str[i];
            i++;
        }
        if(coeStr.empty()) return false;
        int coe = atoi(coeStr.c_str());
        if(op == '-') coe = -coe;

        int exp;
        
        if(i < n && str[i] == '^') {
            i++;
            string expStr;
            while(i < n && isdigit(str[i])) {
                expStr += str[i];
                i++;
            }
            if(expStr.empty()) return false;
            exp = atoi(expStr.c_str());
        } else {
         
            exp = 0;
        }
        pl.insert(coe, exp);
    }
    return i == n;
}


PolyList addPoly(PolyList &A, PolyList &B) {
    PolyList res;
    PolyNode *p = A.head->next;
    PolyNode *q = B.head->next;
    PolyNode *r = res.head;
    while(p != NULL && q != NULL) {
        if(p->exp < q->exp) {
            r->next = new PolyNode(p->coe, p->exp);
            r = r->next;
            p = p->next;
        } else if(p->exp > q->exp) {
            r->next = new PolyNode(q->coe, q->exp);
            r = r->next;
            q = q->next;
        } else {
            int newCoe = p->coe + q->coe;
            if(newCoe != 0) {
                r->next = new PolyNode(newCoe, p->exp);
                r = r->next;
            }
            p = p->next;
            q = q->next;
        }
    }
    while(p != NULL) {
        r->next = new PolyNode(p->coe, p->exp);
        r = r->next;
        p = p->next;
    }
    while(q != NULL) {
        r->next = new PolyNode(q->coe, q->exp);
        r = r->next;
        q = q->next;
    }
    return res;
}

void printPoly(PolyList &pl) {
    PolyNode *p = pl.head->next;
    if(p == NULL) return;
    bool first = true;
    while(p != NULL) {
        int c = p->coe;
        int e = p->exp;
        if(first) {
            if(c > 0) cout << c;
            else cout << "-" << -c;
            first = false;
        } else {
            if(c > 0) cout << "+" << c;
            else cout << "-" << -c;
        }
       
        if(e > 0) {
            cout << "^" << e;
        }
        p = p->next;
    }
    cout << endl;
}

int main() {
    string line1, line2;
    cin >> line1;
    cin >> line2;

    PolyList p1, p2;
    bool ok1 = parsePoly(line1, p1);
    bool ok2 = parsePoly(line2, p2);
    if(!ok1 || !ok2) {
        cout << "输入表达式不合规" << endl;
        return 0;
    }
    PolyList ans = addPoly(p1, p2);
    printPoly(ans);
    return 0;
}
