/*

Cpp program to reverse a number using stack

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

    // Size of stack
    int size()
    {
        return dataElements.size();
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

// Pushing number's digits into stack
void PushNumbersToStack(int num, Stack<int> &numStack)
{
    if (num == 0)
        return;
    numStack.push(num % 10);
    PushNumbersToStack(num / 10, numStack);
}

// Converting number stack into actual number
int PushStackToNumbers(Stack<int> &numStack, int tens, int curNum = 0)
{
    if (numStack.empty())
    {
        return 0;
    }
    int stackElement = numStack.top();
    numStack.pop();
    curNum = PushStackToNumbers(numStack, tens * 10, curNum);
    curNum += (stackElement * tens);
    return curNum;
}

int main()
{
    int num = 4861;
    Stack<int> numberStack;
    std::cout << std::endl
              << "Given number : " << num;
    PushNumbersToStack(num, numberStack);
    std::cout << std::endl
              << "Reversing Numbers : ";
    num = PushStackToNumbers(numberStack, 1);
    std::cout << num;
    return 0;
}
