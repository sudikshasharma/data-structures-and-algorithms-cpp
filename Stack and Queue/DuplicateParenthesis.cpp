/*

Given a balanced expression. Find if it contains duplicate/redundent set of parenthesis. A set of parenthesis are redundent
if the same subexpression is surrounded by multiple parenthesis.

For example,

Input:
((a+b)+((c+d)))

Output:
true or 0

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool DiscardElements(stack<char> &stk)
{
    if (stk.top() == '(')
    {
        return true;
    }
    while (stk.top() != '(')
    {
        stk.pop();
    }
    stk.pop();
    return false;
}

bool DuplicateParenthesis(string str)
{
    stack<char> helperStack;
    bool status = false;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ')')
        {
            status = DiscardElements(helperStack);
            if (status)
                return true;
        }
        else
            helperStack.push(str[i]);
    }
    return false;
}

int main()
{
    string str = "((a+b))";
    std::cout << std::endl
              << "Given expression : " << str << std::endl
              << "Does it contain duplicate parenthesis : " << DuplicateParenthesis(str);
    return 0;
}
