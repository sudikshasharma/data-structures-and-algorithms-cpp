/*

Write a program to generate all possible n pairs of balanced parentheses
'(' and ')'. Balanced parentheses means that for every pair of parentheses
it must has '(' before its ')' and can have other pairs in between or after
or before this pair of parenthesis.
Take no. of pairs as input. Print all possible combinations of parentheses as output

For example,
Input:
2

Output:
()()
(())

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void GenerateBrackets(int n, int openCount, int closeCount, string brackets)
{
    if (openCount == n && closeCount == n)
    {
        std::cout << brackets << std::endl;
        return;
    }
    if (openCount < n)
    {
        brackets += '(';
        GenerateBrackets(n, openCount + 1, closeCount, brackets);
        brackets.erase(brackets.end() - 1);
    }
    if (openCount > closeCount)
    {
        brackets += ')';
        GenerateBrackets(n, openCount, closeCount + 1, brackets);
        brackets.erase(brackets.end() - 1);
    }
}

int main()
{
    int n = 4;
    std::cout << std::endl
              << "For given no. of pairs = " << n << " ,all possible combinations of parentheses are : " << std::endl;
    GenerateBrackets(n, 0, 0, "");
    return 0;
}