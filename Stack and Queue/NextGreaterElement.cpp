/*

Given an array, return the next greater element for every element. The next greater element
for an element x is the first greater element on the right side of x in the array. Elements
for which no greater element exist, consider the next greater element as -1.

For example,

Input:
4, 5, 2, 25

Output:
5, 25, 25, -1
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void PushElements(vector<int> &v, int el, int count)
{
    for (int i = 0; i < count; i++)
        v.push_back(el);
}

vector<int> NextGreaterElement(vector<int> v)
{
    stack<int> helperStack;
    vector<int> vec;
    int elementCout = 1;
    helperStack.push(v[0]);
    int vSize = v.size();
    for (int i = 1; i < vSize; i++)
    {
        if (helperStack.top() < v[i])
        {
            PushElements(vec, v[i], elementCout);
            helperStack.pop();
            helperStack.push(v[i]);
            elementCout = 1;
        }
        else
        {
            ++elementCout;
        }
    }
    PushElements(vec, -1, elementCout);
    return vec;
}

void Print(vector<int> numVec)
{
    for (int i = 0; i < numVec.size(); i++)
    {
        std::cout << numVec[i] << ", ";
    }
}

int main()
{
    vector<int> numVec = {4, 5, 2, 25};
    std::cout << std::endl
              << "Given number vector : ";
    Print(numVec);
    numVec = NextGreaterElement(numVec);
    std::cout << std::endl
              << "Number vector after pushing next greater elements : ";
    Print(numVec);
    return 0;
}
