/*

Given n friends, each one can remain single or can be paired up with some other friend.
Each friend can be paired only once. Find out the total number of ways in which friends
can remain single or can be paired up.

For example,

Input:
3

Output:
4

Explanation:
{1}, {2}, {3} : all single
{1}, {2, 3} : 2 and 3 paired but 1 is single.
{1, 2}, {3} : 1 and 2 are paired but 3 is single.
{1, 3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1, 2} and {2, 1} are considered same

*/

#include <iostream>

using namespace std;

int FriendsPairing(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return FriendsPairing(n - 1) + (n - 1) * FriendsPairing(n - 2); // If nth person remains single, we recurse f(n – 1). Else if nth person pairs up with any of the remaining n – 1 persons. We get (n – 1) * f(n – 2)
}

int main()
{
    int num = 8;
    std::cout << "Number of friends : " << num;
    std::cout << std::endl
              << "Number of ways the frineds can be paired : " << FriendsPairing(num);
    return 0;
}