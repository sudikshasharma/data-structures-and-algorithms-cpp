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

    // Return head (works as Getter)
    Node *Begin()
    {
        return head;
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

    //*& is used so that ref. of variable is passed and can't be reassigned (changed)
    void LinkedListReversal(Node *head)
    {
        if (head->next == NULL)
        {
            this->head = head;
            head->next;
            return;
        }
        Node *temp = head->next;
        LinkedListReversal(head->next);
        temp->next = head;
        head->next = NULL;
    }

    void LinkedListReversal_Iteration() // Following iterative approach to reverse linked list
    {
        Node *curNode = head;
        Node *nextNode = head;
        Node *prevNode = NULL;
        while (curNode != NULL)
        {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
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
    l.print();
    l.LinkedListReversal(l.Begin());
    std::cout << std::endl
              << "Linked List after reversal :" << std::endl;
    l.print();
    l.LinkedListReversal_Iteration();
    std::cout << std::endl
              << "Linked List after reversal (using Iterative approach) :" << std::endl;
    l.print();
    return 0;
}
