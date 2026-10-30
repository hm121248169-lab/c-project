#include<bits/stdc++.h>
using namespace std;




template <class T>
class MyQueue
{

public:

       MyQueue(int num);

       ~MyQueue ();

       bool insert(T item);      // 元素入队列函数

       T remove();                   //元素出队列函数

private:

       T *data;

       int maxCount;    //队列的最大容量

       int  front,rear;      //队头和队尾为数组下标

};

template <class T>

MyQueue<T>::MyQueue(int num){
    maxCount=num;
    data=new T[maxCount];
    front=rear=0;
}

template <class T>

MyQueue<T>::~MyQueue(){
    delete [] data;

}


template<class T>
bool MyQueue<T>::insert(T item)
{
    if (rear == maxCount)
    {
        return false; //数组存满，不能再放元素
    }
    data[rear] = item;
    rear++; //队尾往后挪一位
    return true;
}

template<class T>
T MyQueue<T>::remove()
{
    T val = data[front];
    front++; //队头向后移动，代表元素取出
    return val;
}


int main()  {


MyQueue<char> q( 3 ) ;

q.insert( 'A' ) ;

q.insert( 'B' ) ;

q.insert( 'C' ) ;

 

cout << q.remove() ;

cout << q.remove() ;

cout << q.remove() << endl; 

return 0;

}