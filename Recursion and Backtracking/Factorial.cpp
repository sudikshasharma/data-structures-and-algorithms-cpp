#include <iostream>

using namespace std;

int Factorial(int num)
{
    if (num == 1 || num == 0)
        return 1;
    return num * Factorial(num - 1);
}

int main()
{
    int num;
    std::cout << "Find The Factorial" << std::endl
              << "Enter the number : ";
    std::cin >> num;
    std::cout << std::endl
              << "Factorial is : " << Factorial(num);
    return 0;
}