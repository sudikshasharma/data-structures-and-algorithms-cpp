/*

Give a grid of in n X m matrix. The cell is either empty with '0' character or is blocked with 'X' character.
There's a rat at the starting index (0,0) of the grid and a mice at last index (n-1,m-1) of the grid. Find the
way for the rat to reach mice. There exists only a unique way. The rat can move in up, down, left and right direction.
Print the grid with the path where 1 is the path covered.

Take input as a vector of strings containing the blocked path.
Print matrix with the unique path.

For example,
Input:
"OOOOOOO"
"XOXOOXO"
"OOXXXXX"
"XOOOOXX"
"XXOXOOO"

Output:
 1 1 0 0 0 0 0
 0 1 0 0 0 0 0
 0 1 0 0 0 0 0
 0 1 1 1 1 0 0
 0 0 0 0 1 1 1

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintPath(vector<vector<int>> numSet)
{
    std::cout
        << std::endl
        << "Unique Path for Rat to traverse :" << std::endl;
    for (int i = 0; i < numSet.size(); i++)
    {
        for (int j = 0; j < numSet[i].size(); j++)
        {
            std::cout << " " << numSet[i][j];
        }
        std::cout << std::endl;
    }
}

vector<vector<int>> FindPath(int i, int j, int n, int m, vector<string> arr, vector<vector<int>> &solutionBoard)
{
    if (solutionBoard[n - 1][m - 1] == 1)
    {
        return solutionBoard;
    }
    if (i >= n || j >= m || i < 0 || j < 0)
    {
        return solutionBoard;
    }
    if (arr[i][j] == 'X' || solutionBoard[i][j] == 1)
    {
        return solutionBoard;
    }
    solutionBoard[i][j] = 1;
    if (solutionBoard[n - 1][m - 1] != 1)
    {
        solutionBoard = FindPath(i, j + 1, n, m, arr, solutionBoard);
        solutionBoard = FindPath(i, j - 1, n, m, arr, solutionBoard);
        solutionBoard = FindPath(i + 1, j, n, m, arr, solutionBoard);
        solutionBoard = FindPath(i - 1, j, n, m, arr, solutionBoard);
    }
    if (solutionBoard[n - 1][m - 1] != 1)
        solutionBoard[i][j] = 0;
    return solutionBoard;
}

vector<vector<int>> RatAndMice(vector<string> arr)
{
    int rows = arr.size();
    int col = arr[0].size();
    vector<vector<int>> solutionBoard(rows, vector<int>(col, 0));
    return FindPath(0, 0, rows, col, arr, solutionBoard);
}

int main()
{
    vector<vector<int>> numSet;
    vector<string> arr = {
        {"OOOOOOO"},
        {"XOXOOXO"},
        {"OOXXXXX"},
        {"XOOOOXX"},
        {"XXOXOOO"}};
    numSet = RatAndMice(arr);
    PrintPath(numSet);
    return 0;
}