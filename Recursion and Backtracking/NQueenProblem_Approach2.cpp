/*

    Cpp program to print all the configurations of placing 'n' number of queens in n X n chess board. Also print the possible number of confugrations.
    Print '0' with no queen and '1' with queen on the board.

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintBoard(vector<vector<int>> board, int n)
{
    std::cout << std::endl
              << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

bool IsSafe(vector<vector<int>> board, int n, int i, int j)
{
    for (int x = 0; x <= i; x++)
    {
        if (board[i][x] != 0 || board[x][j] != 0)
            return false;
        if (i - x >= 0 && j - x >= 0 && board[i - x][j - x] != 0)
            return false;
        if (i - x >= 0 && j + x < n && board[i - x][j + x] != 0)
            return false;
    }
    return true;
}

int NumOfWays(vector<vector<int>> &board, int i, int n)
{
    int ways = 0;
    if (i == n)
    {
        PrintBoard(board, n);
        return 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (board[i][j] == 0 && IsSafe(board, n, i, j))
        {
            board[i][j] = 1;
            ways += NumOfWays(board, i + 1, n);
            board[i][j] = 0;
        }
    }
    return ways;
}

int NQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    return NumOfWays(board, 0, n);
}

int main()
{
    int n = 8;
    std::cout << std::endl
              << "All possible configurations with " << n << " queens : " << NQueen(n);
    return 0;
}