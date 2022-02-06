/*

Given a number 'n' and a modern phone keypad. Find out all possible
strings generated using that number.

Keypad codes: 1 = "", 2 = "ABC", 3 = "DEF", 4 = "GHI", 5 = "JKL", 6 = "MNO", 7 = "PQRS", 8 = "TUV", 9 = "WXYZ"

For example,

Input:
23

Output:
AD
AE
AF
BD
BE
BF
CD
CE
CF

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> keypadChar = {"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void FindPossibleCombinations(int curIndex, string word, vector<int> num)
{
    if (curIndex == num.size())
    {
        std::cout << word << std::endl;
        return;
    }
    int keySize = keypadChar[num[curIndex] - 1].size();
    for (int i = 0; i <= keySize; i++)
    {
        if ((i == keySize && keySize == 0) || (keySize != 0 && i < keySize))
        {
            char ch = keypadChar[num[curIndex] - 1][i];
            if (ch != '\0') ///////This is to avoid problems if the keypad's code is empty. For example, in case of 1, there is empty code.
                word += ch;
            FindPossibleCombinations(curIndex + 1, word, num);
            if (ch != '\0')
                word.erase(word.end() - 1);
        }
    }
}

vector<int> ConverNumToVector(int n, vector<int> vec)
{
    while (n != 0)
    {
        vec.insert(vec.begin(), n % 10);
        n /= 10;
    }
    return vec;
}

int main()
{
    int n = 23;
    vector<int> numVec;
    std::cout << std::endl
              << "Given number : " << n;
    numVec = ConverNumToVector(n, numVec);
    std::cout << std::endl
              << "All possible keypad combinations : " << std::endl;
    FindPossibleCombinations(0, "", numVec);
    return 0;
}