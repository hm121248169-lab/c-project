#include<iostream>   // 引入输入输出库，用来 cin、cout
using namespace std; // 使用标准命名空间，不然要写 std::cin std::cout

struct Node {        // 定义链表节点结构体
    int data;        // 节点里面存的数据，整数
    Node* next;      // 指针，存下一个节点的地址
};

// 创建链表，带空头结点，输入-1结束
Node* createList() {
    Node* head = new Node;  // 新建头结点（空头结点，不存有效数据）
    head->next = NULL;      // 头结点一开始后面没有节点，置空
    Node* tail = head;      // tail尾指针，一开始指向头结点，用来尾插
    int val;                // 临时变量，接收每次输入的数字
    while (cin >> val && val != -1) { // 不断读数字，读到 -1 就停止
        Node* p = new Node;  // 新建一个节点
        p->data = val;      // 把输入的值放进这个节点
        p->next = NULL;     // 新节点后面暂时没有节点
        tail->next = p;     // 原来的尾节点接上这个新节点
        tail = p;           // tail更新，移到新的尾巴节点
    }
    return head;            // 返回头结点地址
}

// 打印链表
void printList(Node* head) {
    Node* p = head->next;   // p从第一个有效节点开始（跳过空头）
    if (p == NULL) return; // 如果链表没有有效节点，直接返回不打印
    while (p != NULL) {     // p不为空，说明还有节点要打印
        cout << p->data;    // 输出当前节点的数据
        if (p->next != NULL) { // 如果后面还有节点
            cout << "-->";  // 打印分隔箭头
        }
        p = p->next;        // p走到下一个节点
    }
    cout << endl;           // 全部打完换行
}

// 一遍遍历：找到最小节点，移到最前面
void Findmin(Node* head)
{
    // head->next==NULL：没有有效节点
    // head->next->next==NULL：只有1个有效节点
    // 这两种情况不需要移动，直接return
    if (head->next == nullptr || head->next->next == nullptr)
        return;

    Node* p = head;         // 遍历指针p，p永远是【待检查节点的前驱】，起点在head
    Node* preMin = head;    // preMin：记录最小节点的前驱，默认第一个节点最小

    // p->next != nullptr：p后面还有节点可以检查
    while (p->next != nullptr)
    {
        // p->next 是当前正在检查的节点
        // preMin->next 是目前已知的最小节点
        if (p->next->data < preMin->next->data)
        {
            preMin = p;     // 发现更小的节点，把它的前驱p存到preMin
        }
        p = p->next;       // p往后走，准备检查下一个节点
    }

    Node* minNode = preMin->next; // minNode就是值最小的那个节点
    if (minNode == head->next)    // 如果最小节点本来就在第一个位置
        return;                    // 不用移动，直接结束

    preMin->next = minNode->next; // 把最小节点从链表上摘下来（前驱接上最小节点的下一个）
    minNode->next = head->next;   // 最小节点的后面，接上原来的第一个有效节点
    head->next = minNode;         // 头结点后面接上最小节点，放到最前面
}

int main() {
    Node* head = createList(); // 创建链表，拿到头结点
    printList(head);           // 打印原始链表
    Findmin(head);             // 调用函数，把最小节点移到最前面
    printList(head);           // 打印修改之后的链表
    return 0;                  // 程序正常结束
}
