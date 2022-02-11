/*

Cpp program to create a stack using vector and implement its basic operations like push, pop etc. using oop.
The given program is written in the way the actual class 'Stack' is defined in stl.

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
};

int main()
{
    Stack<char> string;
    std::cout << std::endl
              << "Creating character stack .... ";
    string.push('s');
    string.push('u');
    string.push('d');
    string.push('o');
    std::cout << std::endl
              << "Stack created...popping and printing elements :";
    while (!string.empty())
    {
        std::cout << std::endl
                  << string.top();
        string.pop();
    }
    return 0;
}
