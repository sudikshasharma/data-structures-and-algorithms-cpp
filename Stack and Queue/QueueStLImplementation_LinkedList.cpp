/*

Cpp program to create a queue (of dynamic size) using linked list and implement its basic operations like push, pop etc. using oop.
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

public:
    Queue() : front(NULL), rear(NULL) {}

    bool empty()
    {
        return front == NULL;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (front == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }

    void pop()
    {
        if (!empty())
        {
            Node<T> *tempNode = front;
            front = tempNode->next;
            tempNode->next = NULL;
            delete tempNode;
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
    Queue<char> queue;
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
