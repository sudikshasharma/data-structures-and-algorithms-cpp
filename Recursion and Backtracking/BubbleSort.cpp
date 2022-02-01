#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void SwapValues(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

void BubbleSort(int mainIndex, int index, vector<int> &v)
{
    static bool isSwapped = false;
    if (mainIndex == v.size() - 1)
    {
        return;
    }
    if (index >= v.size() - 1)
    {
        return;
    }
    if (v[index] > v[index + 1])
    {
        isSwapped = true;
        SwapValues(v[index], v[index + 1]);
    }
    BubbleSort(mainIndex, index + 1, v);
    if (isSwapped)
    {
        isSwapped = false;
        BubbleSort(mainIndex + 1, mainIndex + 1, v);
    }
}

void PrintNumbers(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {1, 6, 4, 3, 9, 12, 8, 34};
    std::cout << "Given Array : ";
    PrintNumbers(v);
    BubbleSort(0, 0, v);
    std::cout << std::endl
              << "Sorted Array (using Bubble Sort) : ";
    PrintNumbers(v);
    return 0;
}