/*

Cpp program to reverse a stack

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
    vector<T> dataElements;

public:
    void push(int data)
    {
        dataElements.push_back(data);
    }

    void pop()
    {
        dataElements.pop_back();
    }

    T top()
    {
        return dataElements.back(); // or return dataElements[dataElements.size()-1];
    }

    bool empty()
    {
        return dataElements.size() == 0;
    }

    // Empty the stack
    void clear()
    {
        while (!empty())
            pop();
    }

    // Print the stack top to bottom
    void print()
    {
        for (int i = dataElements.size() - 1; i >= 0; i--)
            std::cout << std::endl
                      << dataElements[i];
    }

    // Insert an element at the bottom of the stack (unlike regular push at the top of stack)
    void insertAtBottom(T data)
    {
        if (empty())
        {
            push(data);
            return;
        }
        T dataElement = top();
        pop();
        insertAtBottom(data);
        push(dataElement);
    }

    // Reverse the stack
    void reverse()
    {
        if (empty())
            return;
        T dataElement = top();
        pop();
        reverse();
        insertAtBottom(dataElement);
    }
};

int main()
{
    Stack<char> string;
    char dataToInsert = 'v';
    std::cout << std::endl
              << "Creating character stack .... ";
    string.push('s');
    string.push('u');
    string.push('d');
    string.push('o');
    std::cout << std::endl
              << "Stack created...popping and printing elements :";
    string.print();
    std::cout << std::endl
              << "Stack created...reversing the stack...";
    string.reverse();
    string.print();
    return 0;
}
