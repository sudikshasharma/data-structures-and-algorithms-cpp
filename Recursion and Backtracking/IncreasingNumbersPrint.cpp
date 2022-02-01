#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> IncreasingNumbers(int N)
{
    if (N <= 0)
    {
        return vector<int>();
    }
    vector<int> v = IncreasingNumbers(N - 1);
    v.push_back(N);
    return v;
}

void PrintNumbers(vector<int> v, int num)
{

    std::cout << "Increasing Order upto " << num << " : ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

int main()
{
    int num;
    std::cout << std::endl
              << "Enter number : ";
    std::cin >> num;
    vector<int> v;
    v = IncreasingNumbers(num);
    PrintNumbers(v, num);
    return 0;
}