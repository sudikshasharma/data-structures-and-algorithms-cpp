/*

Cpp program to solve and print sudoku

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintMat(vector<vector<int>> mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool CanBePlaced(vector<vector<int>> mat, int num, int row, int col, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (mat[row][i] == num || mat[i][col] == num)
            return false;
    }
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (mat[i][j] == num)
                return false;
        }
    }
    return true;
}

void SudokuSolver(vector<vector<int>> mat, int i, int j, int n)
{
    if (i == n)
    {
        PrintMat(mat, n);
        return;
    }
    if (j == n)
    {
        SudokuSolver(mat, i + 1, 0, n);
        return;
    }
    if (mat[i][j] != 0)
    {
        SudokuSolver(mat, i, j + 1, n);
        return;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (CanBePlaced(mat, num, i, j, n))
        {
            mat[i][j] = num;
            SudokuSolver(mat, i, j + 1, n);
        }
    }
    mat[i][j] = 0;
}

int main()
{
    int n = 9;
    vector<vector<int>> mat = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    SudokuSolver(mat, 0, 0, n);
    return 0;
}