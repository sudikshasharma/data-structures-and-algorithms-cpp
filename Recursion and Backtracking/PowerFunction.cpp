#include <iostream>

using namespace std;

int PowerFunction(int num, int pow)
{
    if (pow == 0)
        return 1;
    return num * PowerFunction(num, pow - 1);
}

int PowerFunctionOptimized(int num, int pow) // For even no. , a^n = (a^n/2)^2      // For odd no. , a^n = a.(a^(n-1)/2)^2
{
    if (pow == 1)
        return num;
    int base;
    if (pow % 2 == 0)
    {
        base = PowerFunctionOptimized(num, pow / 2);
        base *= base;
    }
    else
    {
        base = PowerFunctionOptimized(num, (pow - 1) / 2);
        base *= (base * num);
    }
    return base;
}

int main()
{
    int num = 4, size = 9;
    std::cout << std::endl
              << num << " raised to the power " << size << " = " << PowerFunction(num, size);
    std::cout << std::endl
              << num << " raised to the power " << size << " (Optimized Calculation) = " << PowerFunctionOptimized(num, size);
    return 0;
}