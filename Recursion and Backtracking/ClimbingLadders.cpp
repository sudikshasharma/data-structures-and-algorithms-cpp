/*

Given a ladder with n number of steps. Find the no. of ways a person, standing at the bottom, can reach at the last step
of the ladder. He can either climb 1, 2 or 3 steps at a time.

For example,
Input:
4

Output:
7

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int StepCount(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return StepCount(n - 1) + StepCount(n - 2) + StepCount(n - 3);
}

int main()
{
    int n = 4;
    std::cout << std::endl
              << "Total ladder steps : " << n;
    std::cout << std::endl
              << "Total ways to climb the ladder (Conidering that we can take either 1,2 or 3 step at a time) : " << StepCount(n);

    return 0;
}