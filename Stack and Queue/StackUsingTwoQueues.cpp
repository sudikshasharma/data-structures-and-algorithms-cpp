/*

Cpp program to create a stack using 2 queues internally and implement its basic operations like push, pop etc. using oop.
The given program is written in the way the actual class 'Stack' is defined in stl.

*/

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Stack
{
    queue<T> q1;
    queue<T> q2;

public:
    bool empty()
    {
        return (q1.empty() && q2.empty());
    }

    void push(T data)
    {
        if (!q1.empty())
            q1.push(data);
        else
            q1.push(data);
    }

    void pop() // copying non empty queue's data to empty queue except of the last element in the non empty queue
    {
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                T el = q1.front();
                q1.pop();
                if (q1.empty())
                    break;
                q2.push(el);
            }
        }
        else if (!q2.empty())
        {
            while (!q2.empty())
            {
                T el1 = q2.front();
                q2.pop();
                if (q2.empty())
                    break;
                q1.push(el1);
            }
        }
    }

    T top() // Or we can follow the same procedure as pop (and also copying the last element of the non empty queue)
    {
        if (!q1.empty())
            return q1.back();
        else
            return q2.back();
    }
};

int main()
{
    Stack<char> stack;
    std::cout << std::endl
              << "Creating character stack (internally using 2 queues).... ";
    stack.push('s');
    stack.push('u');
    stack.push('d');
    stack.push('o');
    std::cout << std::endl
              << "Stack created...popping and printing elements :";
    while (!stack.empty())
    {
        std::cout << std::endl
                  << stack.top();
        stack.pop();
    }
    return 0;
}
