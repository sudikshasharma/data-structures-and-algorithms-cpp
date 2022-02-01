#include <iostream>

using namespace std;

int Fibonacci(int num)
{
    int sum;
    if (num == 0 || num == 1)
        return num;
    return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main()
{
    int num;
    std::cout << "Find The Fibonacci sum" << std::endl
              << "Enter the sequence count : ";
    std::cin >> num;
    std::cout << std::endl
              << "Fibonacci Sum is : " << Fibonacci(num);
    return 0;
}