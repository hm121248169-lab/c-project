#include<bits/stdc++.h>

template <class T>
class queue
{
public:
    queue(int num);
    ~queue();
    bool insert(T item);      // 元素入队列函数
    T remove();                   //元素出队列函数
private:
    T *data;
    int maxCount;    //队列的最大容量
    int front, rear;      //队头和队尾为数组下标
};

template <class T>
queue<T>::queue(int num) {
    maxCount = num + 1;
    data = new T[maxCount];
    front = 0;
    rear = 0;
}

template <class T>
queue<T>::~queue() {
    delete[] data;
}

template <class T>
bool queue<T>::insert(T item) {
    if ((rear + 1) % maxCount == front) {
        return false;
    }
    data[rear] = item;
    rear = (rear + 1) % maxCount;
    return true;
}

template <class T>
T queue<T>::remove() {
    if (front == rear) {
        throw std::runtime_error("Queue is empty");
    }
    T item = data[front];
    front = (front + 1) % maxCount;
    return item;
}

int main()
{
    queue<char> q(3);
    q.insert('A');
    q.insert('B');
    q.insert('C');
    
    std::cout << q.remove();
    std::cout << q.remove();
    std::cout << q.remove() << std::endl;
    return 0;
}