/*

Cpp program to find kth element from the last of a Linked List

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

    // Return position of kth element from the last
    int KthLastElement(int k)
    {
        Node *temp1 = head;
        for (int i = 0; i < k; i++)
        {
            temp1 = temp1->next;
        }
        Node *temp2 = head;
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp2->data;
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
    int k = 5;
    List l;
    std::cout << "Linked List :" << std::endl;
    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.print();
    std::cout << std::endl
              << k << "th last element in Linked List : " << l.KthLastElement(k);
    return 0;
}
