/*
    Cpp program to print 2d array in spiral form. eg. A= 1,2,3,    Print:1,2,3,6,9,8,7,4,5
                                                         4,5,6,
                                                         7,8,9
*/

#include <iostream>

int main()
{
    int **a, row, col,left,right,up,down,flag=0,i=0;
    std::cout << "Enter number of array rows : ";
    std::cin >> row;
    std::cout << "Enter number of array columns : ";
    std::cin >> col;
    a = new int*[row];
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
            std::cin >> a[i][j];
        }
    }
    std::cout << std::endl
              << "Array spiral form : " << std::endl;
    while(flag==0)
    {
      flag=1;
      for(right=i;right<col-i;right++)
      {
        std::cout<<a[i][right]<<" , ";
        flag=0;
      }
      for(down=i+1;down<row-i;down++)
      {
        std::cout<<a[down][right-1]<<" , ";
        flag=0;
      }
      for(left=col-2-i;left>=i;left--)
      {
        std::cout<<a[down-1][left]<<" , ";
        flag=0;
      }
      for(up=row-2-i;up>i;up--)
      {
        std::cout<<a[up][left+1]<<" , ";
        flag=0;
      }
      i++;
    }
    return 0;
}