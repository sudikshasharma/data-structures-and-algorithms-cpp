#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int FirstOccurence(int *arr, int key, int size)
{
    int index = 0;
    if (size == 0)
        return -1;
    if (arr[0] == key)
        return 0;
    index = FirstOccurence(arr + 1, key, size - 1);
    if (index != -1)
        return index + 1;
    return index;
}

int LastOccurence(int *arr, int key, int size)
{
    int index = 0;
    if (size == 0)
        return -1;
    index = LastOccurence(arr + 1, key, size - 1);
    if (arr[0] == key && index <= 0)
        return 0;
    if (index != -1)
        return index + 1;
    return index;
}

vector<int> FindAllOccurences(int k, vector<int> v)
{
    static int count = 0;
    if (count == v.size())
    {
        return vector<int>();
    }
    ++count;
    vector<int> newVect = FindAllOccurences(k, v);
    --count;
    if (v[count] == k)
    {
        newVect.insert(newVect.begin(), count);
    }
    return newVect;
}

void PrintAllOccurences(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    if (v.size() == 0)
        std::cout << "None";
}

int main()
{
    int arr[] = {0, 2, 3, 1, 2, 3, 5, 6}, size, key = 2;
    vector<int> v = {0, 2, 3, 1, 2, 3, 2, 5, 6};
    size = sizeof(arr) / sizeof(int);
    std::cout << std::endl
              << "First Occurence of " << key << " :" << FirstOccurence(arr, key, size);
    std::cout << std::endl
              << "Last Occurence of " << key << " :" << LastOccurence(arr, key, size);
    v = FindAllOccurences(key, v);
    std::cout << std::endl
              << "All Occurences of " << key << " :";
    PrintAllOccurences(v);
    return 0;
}