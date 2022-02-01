/*

You are given N tiles of size 1 X M. There us a floor of size N X M which you have to 
cover with tiles. Find the number of ways the floor can be completely covered if you 
can place the tiles in both horizontal and vertical manner.

Input Format:
In the function, two integer N and M are passed.

Output Format:
Return a single integer denoting the number of ways.

Sample Input:
4 3

Sample Output:
3

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int TilingProblem(int n, int m)
{
    if (n < m)
        return 1;
    return TilingProblem(n - m, m) + TilingProblem(n - 1, m);
}

int main()
{
    int n = 22, m = 6;
    std::cout << "Given N : " << n << std::endl
              << "Given M : " << m;
    std::cout << std::endl
              << "Number of ways the tiles can be placed : " << TilingProblem(n, m);
    TilingProblem(n, m);
    return 0;
}