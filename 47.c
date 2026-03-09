#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入节点
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// 删除链表中值为data的节点
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return head;
    }
    
    // 如果要删除的是头节点
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // 查找要删除的节点
    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    // 如果找到了要删除的节点
    if (current->next != NULL) {
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    
    return head;
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int num;
    
    // 输入数字，直到遇到-1
    while (scanf("%d", &num) && num != -1) {
        head = insertAtHead(head, num);
    }
    
    // 输入要删除的数字
    scanf("%d", &num);
    
    // 删除指定数字的节点
    head = deleteNode(head, num);
    
    // 输出链表内容
    if (head != NULL) {
        printList(head);
    }
    
    // 释放内存
    freeList(head);
    
    return 0;
}