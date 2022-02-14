/*

Given a queue of integers of even length, rearrange the elements by interleaving the first half
of the queue with the second half of the queue.
Example:

Input:
1 2 3 4 5 6 7 8 9 10

Output:
1 6 2 7 3 8 4 9 5 10

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> InterLeave(queue<int> q)
{
    queue<int> q2;
    queue<int> q3;
    int qSize = q.size();
    for (int i = 0; i < qSize / 2; i++)
    {
        q2.push(q.front());
        q.pop();
    }
    for (int i = 0; i < qSize; i++)
    {
        if (i % 2 == 0)
        {
            q3.push(q2.front());
            q2.pop();
        }
        else
        {
            q3.push(q.front());
            q.pop();
        }
    }
    return q3;
}

void Print(queue<int> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    std::cout << std::endl
              << "Queue of numbers : ";
    Print(q);
    q = InterLeave(q);
    std::cout << std::endl
              << "Queue after interleaving : ";
    Print(q);
    return 0;
}
