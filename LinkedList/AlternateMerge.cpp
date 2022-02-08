/*

Cpp program to merge nodes of one linked list in the alternate positions of the other linked list and return the head of the new merged linked list

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

    // Merging nodes of root2 linked list in the alternate positions of this linked list
    Node *AlternateMerge(Node *root2)
    {
        // Complete this function
        Node *root1 = this->head;
        Node *head = root1;
        Node *temp1 = root1;
        Node *temp2 = root2;
        bool isFirstTurn = false;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (!isFirstTurn)
            {
                temp1 = root1->next;
                root1->next = root2;
                root1 = temp1;
            }
            else
            {
                temp2 = root2->next;
                root2->next = root1;
                root2 = temp2;
            }
            isFirstTurn = !isFirstTurn;
        }
        return head;
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
    List l, l2;
    std::cout << std::endl
              << "Linked List 1:" << std::endl;
    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.print();
    std::cout << std::endl
              << "Linked List 2:" << std::endl;
    l2.push_front(13);
    l2.push_front(12);
    l2.push_back(8);
    l2.push_back(6);
    l2.push_back(9);
    l2.print();
    std::cout << std::endl
              << "Merging Linked List.... ";
    l.AlternateMerge(l2.Begin());
    std::cout << "Merged Linked List :" << std::endl;
    l.print();
    return 0;
}
