/*
	Cpp program to print 2d array in wave form. eg. A= 1,2,3,    Print:1,4,7,8,5,2,3,6,9
                                                       4,5,6,
                                                       7,8,9
*/

#include <iostream>

int main()
{
    int **a, row, col;
    std::cout << "Enter number of array rows : ";
    std::cin >> row;
    std::cout << "Enter number of array columns : ";
    std::cin >> col;
    *a = new int[row];
    for (int i = 0; i < row; i++)
    {
        a[i] = new int[col];
    }
    std::cout << std::endl
              << "Enter array elements : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> a[j];
        }
    }
    std::cout << std::endl
              << "Array wave form : " << std::endl;
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < row; j++)
            {
                std::cout << a[j] << " , ";
            }
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                std::cout << a[j] << " , ";
            }
        }
    }
    return 0;
}