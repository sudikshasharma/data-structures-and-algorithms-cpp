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

    // Destroying Node (Calling destructor)
    ~Node()
    {
        // This will work as a recursive call and deletes all the nodes in the linked list. 'delete next' will call the destructor of the next node and so on, thus calling destructor of all the nodes
        if (next != NULL)
            delete next;
        std::cout << std::endl
                  << "Deleting node with data value " << data;
    }

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

    // Deleting the whole linked list (Calling Destructor)
    ~List()
    {
        // This will delete the nodes of the linked list (Check the Node class's destructor definition)
        if (head != NULL)
            delete head;
        head = NULL;
        std::cout << std::endl
                  << "Linked List Deleted";
    }

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

    // Popping the starting node
    void pop_front()
    {
        Node *tempNode = head;
        head = head->next;
        // Nullifying tempNode's next is important. If we delete tempNode without nullifying its next, it'll delete the whole list due to List class's destructor definition (Check its definiton)
        tempNode->next = NULL;
        delete tempNode;
    }

    // Popping the last node and return head
    void pop_back()
    {
        if (head->next == NULL)
        {
            delete head;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp1 = temp->next;
        temp->next = NULL;
        delete (temp1);
        return;
    }

    // Remove a new node at a given position in linked list
    void remove(int pos)
    {
        Node *curNode = head;
        Node *prevNode = NULL;
        int curPos = 0;
        while (curPos != pos)
        {
            prevNode = curNode;
            curNode = curNode->next;
            ++curPos;
            if (curNode->next == NULL)
            {
                // Delete last element if position is out of bounds
                pop_back();
                return;
            }
        }
        prevNode->next = curNode->next;
        curNode->next = NULL;
        delete curNode;
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
    std::cout << std::endl
              << "Pushing 1 :" << std::endl;
    l.push_front(1);
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    l.push_front(2);
    std::cout << std::endl
              << "Pushing 2 in front :" << std::endl;
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Pushing 3 in back :" << std::endl;
    l.push_back(3);
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Inserting 4 at position 0 :" << std::endl;
    l.insert(4, 0);
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Inserting 5 at position 1 :" << std::endl;
    l.insert(5, 1);
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Removing element from position of 2 in linked list : ";
    l.remove(2);
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Removing first element in linked list : ";
    l.pop_front();
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Removing last element in linked list : ";
    l.pop_back();
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    std::cout << std::endl
              << "Searching recursively, position of 5 in linked list : " << l.search(5);
    std::cout << std::endl
              << "Searching iteratively, position of 1 in linked list : " << l.search_Iterative(1);
    std::cout << std::endl
              << "Searching recursively, position of 10 in linked list : " << l.search(10);
    // Here, l's destructor will automatically be called as l is statically initialized and is going out of scope here. Check the List class's destructor definition
    return 0;
}
