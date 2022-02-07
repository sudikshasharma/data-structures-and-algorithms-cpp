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

    // Helper method for search (Recursive Approach)
    int lookForElement(int data, Node *curNode)
    {
        if (curNode == NULL)
            return -1;
        if (curNode->data == data)
            return 0;
        int pos = lookForElement(data, curNode->next);
        if (pos == -1)
            return pos;
        return 1 + pos;
    }

    // Search an element in linked list and return its position. Return -1 if data element doesn't exist (Recursive Approach)
    int search(int data)
    {
        return lookForElement(data, head);
    }

    // Search an element in linked list and return its position. Return -1 if data element doesn't exist (Iterative Approach)
    int search_Iterative(int data)
    {
        int pos;
        Node *temp = head;
        for (pos = 0; temp != NULL; pos++)
        {
            if (temp->data == data)
                return pos;
            temp = temp->next;
        }
        return -1;
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
    std::cout << std::endl
              << "Searching recursively, position of 5 in linked list : " << l.search(5);
    std::cout << std::endl
              << "Searching iteratively, position of 1 in linked list : " << l.search_Iterative(1);
    std::cout << std::endl
              << "Searching recursively, position of 10 in linked list : " << l.search(10);
    return 0;
}
