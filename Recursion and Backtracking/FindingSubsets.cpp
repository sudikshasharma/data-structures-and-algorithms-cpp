/*

Find all subsets of a given string.

Sample Input:
abc

Sample Output:
abc ab ac a bc b c

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindingSubsets(string outStr, string inStr)
{
    if (inStr.empty())
    {
        std::cout << outStr << " ";
        return;
    }
    int inputChar = inStr[0];
    outStr += inStr[0];
    inStr.erase(inStr.begin());
    FindingSubsets(outStr, inStr);
    outStr.erase(outStr.end() - 1);
    FindingSubsets(outStr, inStr);
}

int main()
{
    string str = "abc";
    std::cout << "Subsets of the string " << str << " is :" << std::endl;
    FindingSubsets("", str);
    return 0;
}