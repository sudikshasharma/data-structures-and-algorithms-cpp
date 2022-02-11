/*

Cpp program to create a stack using Linked List and implement its basic operations like push, pop etc. using oop.
The given program is written in the way the actual class 'Stack' is defined in stl.

*/

#include <iostream>

using namespace std;

template <typename T>
class Stack;

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
    friend class Stack;
};

template <typename T>
class Stack
{
    Node<T> *head = NULL;

public:
    Stack() : head(NULL) {}

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        Node<T> *tempNode = head;
        head = head->next;
        tempNode->next = NULL; // Important step otherwise it'll delete the whole list (check Node class's destructor)
        delete tempNode;
    }

    T top()
    {
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack<char> list;
    std::cout << std::endl
              << "Creating character stack .... ";
    list.push('s');
    list.push('u');
    list.push('d');
    list.push('o');
    std::cout << std::endl
              << "Stack created...popping and printing elements :";
    while (!list.empty())
    {
        std::cout << std::endl
                  << list.top();
        list.pop();
    }
    return 0;
}
