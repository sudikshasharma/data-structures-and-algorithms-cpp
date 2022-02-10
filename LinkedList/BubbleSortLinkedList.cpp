/*

Cpp program to sort a linked list using Bubble Sort

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

    // Sort LinkedList using Bubble Sort
    void BubbleSort()
    {
        Node *lastNodeToCheck = NULL;
        Node *curNode = head;
        Node *prevNode = head;
        Node *temp = NULL;
        while (head != lastNodeToCheck)
        {
            while (curNode != lastNodeToCheck)
            {
                if (curNode->next == NULL || curNode->next == lastNodeToCheck)
                {
                    lastNodeToCheck = curNode;
                    continue;
                }
                if (curNode->data > curNode->next->data)
                {
                    if (curNode == head)
                    {
                        head = curNode->next;
                        temp = head->next;
                        prevNode->next = temp;
                        head->next = prevNode;
                        prevNode = head;
                    }
                    else
                    {
                        temp = curNode->next;
                        prevNode->next = temp;
                        curNode->next = temp->next;
                        temp->next = curNode;
                        prevNode = temp;
                    }
                }
                else
                {
                    if (curNode == head)
                        prevNode = head;
                    else
                        prevNode = prevNode->next;
                    curNode = curNode->next;
                }
            }
            prevNode = head;
            curNode = head;
        }
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
              << "Linked List :" << std::endl;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(7);
    l.push_back(-1);
    l.push_back(9);
    l.push_back(1);
    l.push_back(2);
    l.print();
    std::cout << std::endl
              << "Bubble Sorting..." << std::endl;
    l.BubbleSort();
    std::cout << std::endl
              << "Linked List :" << std::endl;
    l.print();
    return 0;
}
