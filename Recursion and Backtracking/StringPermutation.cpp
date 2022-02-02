/*

Find all the possible permutations of a given string.

Sample Input:
abc

Sample Output:
abc acb bac bca cba cab

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void SwapChar(char &ch1, char &ch2)
{
    char tempChar = ch1;
    ch1 = ch2;
    ch2 = tempChar;
}

void StringPermutation(string outStr, string inStr)
{
    if (inStr.size() == 1)
    {
        outStr += inStr[0];
        std::cout << outStr << " ";
        return;
    }
    for (int i = 0; i < inStr.size(); i++)
    {
        if (i != 0)
        {
            SwapChar(inStr[0], inStr[i]);
        }
        char ch = inStr[0];
        outStr += ch;
        inStr.erase(inStr.begin());
        StringPermutation(outStr, inStr);
        outStr.erase(outStr.end() - 1);
        inStr.insert(inStr.begin(), ch);
        if (i != 0)
        {
            SwapChar(inStr[0], inStr[i]);
        }
    }
}

int main()
{
    string str = "abc";
    std::cout << "All possible permutation of string " << str << " is:" << std::endl;
    StringPermutation("", str);
    return 0;
}