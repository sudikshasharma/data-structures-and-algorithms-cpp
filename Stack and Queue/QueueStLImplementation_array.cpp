/*

Cpp program to create a queue (Circular queue) using array and implement its basic operations like push, pop etc. using oop.
The given program is written in the way the actual class 'Queue' is defined in stl.

*/

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
    T *dataElements;
    int totalSize;
    int currentSize;
    int front;
    int rear;

public:
    Queue(int maxSize = 3) : dataElements(new T[maxSize]), totalSize(maxSize), currentSize(0), front(0), rear(0) {}

    bool full()
    {
        return currentSize == totalSize;
    }

    bool empty()
    {
        return currentSize == 0;
    }

    void push(T data)
    {
        if (!full())
        {
            dataElements[rear] = data;
            rear = (rear + 1) % totalSize;
            ++currentSize;
        }
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % totalSize;
            --currentSize;
        }
    }

    T getFront()
    {
        return dataElements[front];
    }

    T getRear()
    {
        return dataElements[rear];
    }
};

int main()
{
    Queue<char> queue(3);
    std::cout << std::endl
              << "Creating character queue .... ";
    queue.push('s');
    queue.push('u');
    queue.push('d');
    queue.push('o');
    std::cout << std::endl
              << "Queue created...popping and printing elements :";
    while (!queue.empty())
    {
        std::cout << std::endl
                  << queue.getFront();
        queue.pop();
    }
    return 0;
}
