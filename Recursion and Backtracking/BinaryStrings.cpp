/*

You are given integer N. Print all binary strings of size N without consecutive ones.

Constraints:
N<=12

Input Format:
In the given function, an integer N is passed as parameter

Output Format:
Return a vector of strings, with all possible strings in a sorted order

Sample Input:
3

Sample Output:
000 001 010 100 101

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void SetBinaryStrings(int curCount, int maxCount, vector<string> &binaryString, string curStr)
{
    if (curCount >= maxCount)
    {
        binaryString.push_back(curStr);
        return;
    }
    curStr += '0';
    SetBinaryStrings(curCount + 1, maxCount, binaryString, curStr);
    curStr.erase(curStr.end() - 1);
    if (curStr[curStr.size() - 1] == '0' || curStr.size() == 0)
    {
        curStr += "1";
        SetBinaryStrings(curCount + 1, maxCount, binaryString, curStr);
    }
}

vector<string> BinaryStrings(int n)
{
    vector<string> vec;
    SetBinaryStrings(0, n, vec, "");
    return vec;
}
void PrintStrings(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

int main()
{
    int num = 5;
    std::cout << " Size : " << num;
    vector<string> v;
    v = BinaryStrings(num);
    std::cout << std::endl
              << "All Possible Strings in sorted order : ";
    PrintStrings(v);
    return 0;
}