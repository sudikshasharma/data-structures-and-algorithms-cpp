/*

Given a M X N grid, find the number of ways to reach the bottom
right corner starting from top left. At each cell you can move right
or down.

Input:
3 3

Output:
6

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int count1 = 0;
void GridWays(int i, int j, int n, int m)
{
    if (i >= n - 1 && j >= m - 1)
    {
        ++count1;
        return;
    }
    if (j < m - 1)
        GridWays(i, j + 1, n, m);

    if (i < n - 1)
        GridWays(i + 1, j, n, m);
}

int main()
{
    int n = 3, m = 3;
    std::cout << "No. of rows : " << n << " No. of columns : " << m;
    GridWays(0, 0, n, m);
    std::cout << std::endl
              << "No. of ways : " << count1;
    return 0;
}