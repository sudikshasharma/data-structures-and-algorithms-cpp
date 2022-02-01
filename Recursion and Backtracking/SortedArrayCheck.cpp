#include <iostream>

using namespace std;

bool IsSorted(int *a, int size)
{
    if (size == 0)
        return true;
    if (a[0] <= a[1] && IsSorted(a + 1, size - 1))
        return true;
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6}, size;
    size = sizeof(arr) / sizeof(int);
    if (IsSorted(arr, size))
        std::cout << "Array is Sorted";
    else
        std::cout << "Not a Sorted Array";
    return 0;
}