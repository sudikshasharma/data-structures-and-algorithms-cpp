/*

Cpp program to create a linked list and implement its basic operations like insertion, deletion etc. using oop.
The given program is written in the way the actual class 'List' is defined in stl.

*/

#include <iostream>

// Forward declaration (of List class) to avoid errors (as List class is defined after Node class. So, it'd give not declared error if Node class uses any member of List class).
class List;

class Node
{
    int data;
    Node *next;

public:
    // Creating a Node (Calling Constructor)
    Node(int val) : data(val), next(NULL) {}

    // making List class a friend class of Node class (List class can access the private members of Node class)
    friend class List;
};

class List
{
    Node *head;
    Node *tail;

public:
    // Creating LinkedList (Calling Constructor)
    List() : head(NULL), tail(NULL) {}

    // Pushing a new node in front
    void push_front(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }

    // Pushing a new node at the end
    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Insert a new node at a given position in linked list
    void insert(int data, int pos)
    {
        Node *newNode = new Node(data);
        if (head == NULL || pos == 0)
        {
            push_front(data);
            return;
        }
        Node *curNode = head;
        Node *prevNode = head;
        int curPos = 0;
        while (curPos != pos && curNode != NULL)
        {
            prevNode = curNode;
            curNode = curNode->next;
            ++curPos;
        }
        prevNode->next = newNode;
        newNode->next = curNode;
        return;
    }

    // Print the linked list
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
    }
};

int main()
{
    List l;
    std::cout << "Linked List :" << std::endl;
    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.insert(4, 0);
    l.insert(5, 1);
    l.print();
    return 0;
}
