/*

Cpp program to create a queue (of dynamic size as well as fixed size) using linked list and implement its basic operations like push, pop etc. using oop.
The given program is written in the way the actual class 'Queue' is defined in stl.

*/

#include <iostream>

using namespace std;

template <typename T>
class Queue;

template <typename T1>
class Node
{
    T1 data;
    Node<T1> *next;

public:
    // Creating a Node (Calling Constructor)
    Node(T1 val) : data(val), next(NULL) {}

    // Destroying Node (Calling destructor)
    ~Node()
    {
        // This will work as a recursive call and deletes all the nodes in the linked list. 'delete next' will call the destructor of the next node and so on, thus calling destructor of all the nodes
        if (next != NULL)
            delete next;
    }

    template <typename T>
    friend class Queue;
};

template <typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;
    int maxSize;
    int curSize;

public:
    // Queue with dynamic size
    Queue() : front(NULL), rear(NULL), maxSize(0), curSize(0) {}
    // Queue with fixed size
    Queue(int defaultSize) : front(NULL), rear(NULL), maxSize(defaultSize), curSize(0) {}

    bool empty()
    {
        return front == NULL;
    }

    void push(T data)
    {
        std::cout
            << std::endl
            << "Pushing " << data;
        if (maxSize == 0 || curSize < maxSize)
        {
            Node<T> *newNode = new Node<T>(data);
            if (front == NULL)
                front = newNode;
            else
                rear->next = newNode;
            rear = newNode;
            if (curSize < maxSize)
                ++curSize;
        }
        else
            std::cout
                << std::endl
                << "Can't push " << data << ". Queue is full. This is a fixed size queue ";
    }

    void pop()
    {
        if (!empty())
        {
            Node<T> *tempNode = front;
            front = tempNode->next;
            tempNode->next = NULL;
            delete tempNode;
            if (maxSize != 0)
                --curSize;
        }
    }

    T getFront()
    {
        return front->data;
        ;
    }

    T getRear()
    {
        return rear->data;
    }
};

int main()
{
    int size = 3;
    Queue<char> queue(size);
    Queue<char> dynamicQueue;
    std::cout << std::endl
              << "Creating character queue with fixed size " << size;
    queue.push('s');
    queue.push('u');
    queue.push('d');
    queue.push('o');
    std::cout << std::endl
              << "Fixed size queue created...popping and printing elements :";
    while (!queue.empty())
    {
        std::cout << std::endl
                  << queue.getFront();
        queue.pop();
    }
    std::cout << std::endl
              << "Creating character queue with dynamic size ";
    dynamicQueue.push('o');
    dynamicQueue.push('u');
    dynamicQueue.push('d');
    dynamicQueue.push('s');
    dynamicQueue.push('h');
    std::cout << std::endl
              << "Dynamic size queue created...popping and printing elements :";
    while (!dynamicQueue.empty())
    {
        std::cout << std::endl
                  << "Popping "
                  << dynamicQueue.getFront();
        dynamicQueue.pop();
    }
    return 0;
}
