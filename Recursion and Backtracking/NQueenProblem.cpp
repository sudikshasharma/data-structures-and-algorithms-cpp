#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool IsValidPlacement(int **board, int row, int col, int n)
{
    int counter = 0;
    while (row - counter >= 0 || col - counter >= 0 || col + counter < n)
    {
        if (row - counter >= 0 && (board[row - counter][col] == 1 || (col - counter >= 0 && board[row - counter][col - counter] == 1)))
            return false;
        if (col + counter < n && (board[row][col + counter] == 1 || (row - counter >= 0 && board[row - counter][col + counter] == 1)))
            return false;
        counter++;
    }
    return true;
}

void PrintBoard(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

int counter = 0;
void PlaceQueens(int **board, int row, int col, int n)
{
    if (col >= n)
        return;
    if (row >= n)
    {
        std::cout << std::endl
                  << n << " Queens Placement :" << std::endl;
        PrintBoard(board, n);
        ++counter;
        return;
    }
    if (IsValidPlacement(board, row, col, n))
    {
        board[row][col] = 1;
        PlaceQueens(board, row + 1, 0, n);
        board[row][col] = 0;
    }
    PlaceQueens(board, row, col + 1, n);
}

int main()
{
    int **board, n = 8;
    board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n]();
    }
    PlaceQueens(board, 0, 0, n);
    std::cout << std::endl
              << "Total Possible Placements : " << counter;
    return 0;
}