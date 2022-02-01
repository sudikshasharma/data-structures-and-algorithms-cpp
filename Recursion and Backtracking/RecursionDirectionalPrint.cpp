#include <iostream>

using namespace std;

void PrintAscending(int maxNum)
{
    if (maxNum < 0)
        return;
    PrintAscending(maxNum - 1);
    std::cout << " " << maxNum;
}

void PrintDescending(int maxNum)
{
    if (maxNum < 0)
        return;
    std::cout << " " << maxNum;
    PrintDescending(maxNum - 1);
}

int main()
{
    int maxNum = 10;
    std::cout << std::endl
              << "Ascending Order : ";
    PrintAscending(maxNum);
    std::cout << std::endl
              << "Descending Order : ";
    PrintDescending(maxNum);
    return 0;
}