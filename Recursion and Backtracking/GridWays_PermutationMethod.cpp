/*

Given a M X N grid, find the number of ways to reach the bottom
right corner starting from top left. At each cell you can move right
or down. [Using Permutation and combination]

Input:
3 3

Output:
6

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * Factorial(n - 1);
}
int GridWays(int n, int m)
{
    // We can only move right or down to reach the end. So, for every possible way, we've to move n-1 times down and m-1 times right. So, no. of ways = all possible combinations of right(R) and down(D) movement. For example, if n=3,m=3..some possible ways could be RRRDDD,DDDRRR,RDRDRD,RRDDRD etc.
    return Factorial(m - 1 + n - 1) / (Factorial(m - 1) * Factorial(n - 1)); // Permutation formula : AllPossibleMoves!/(NumOfRightMoves! * NumOfDownMoves!)
}

int main()
{
    int n = 5, m = 8;
    std::cout << "No. of rows : " << n << " No. of columns : " << m;
    std::cout << std::endl
              << "No. of ways : " << GridWays(n, m);
    return 0;
}