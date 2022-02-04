/*
Give a grid of characters in n X m matrix and a word of string. Return true if the word
exists in the matrix, else return false. The word can be formed from vertically or horizontally
adjacent characters.

Input:
2D matrix of characters and word

Output:
true or false

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool IsFoundWord(int i, int j, int n, int m, vector<vector<char>> &board, string word, vector<vector<int>> &checkBoard, int currentWordIndex)
{
    bool status = false;
    if (word.size() == currentWordIndex)
        return true;
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    if (checkBoard[i][j] == 1)
        return false;
    if (board[i][j] == word[currentWordIndex])
    {
        currentWordIndex++;
        checkBoard[i][j] = 1;
        status = (IsFoundWord(i + 1, j, n, m, board, word, checkBoard, currentWordIndex) || IsFoundWord(i - 1, j, n, m, board, word, checkBoard, currentWordIndex) || IsFoundWord(i, j + 1, n, m, board, word, checkBoard, currentWordIndex) || IsFoundWord(i, j - 1, n, m, board, word, checkBoard, currentWordIndex));
        checkBoard[i][j] = 0;
    }
    return status;
}

bool SearchingWord(int i, int j, int n, int m, vector<vector<char>> &board, string word, vector<vector<int>> &checkBoard)
{
    bool status = false;
    while (!status && i < n)
    {
        status = IsFoundWord(i, j, n, m, board, word, checkBoard, 0);
        j++;
        if (j >= m)
        {
            j = 0;
            i++;
        }
    }
    return status;
}

bool WordSearch(vector<vector<char>> &board, string word)
{
    int rowSize = board.size();
    int colSize = board[0].size();
    vector<vector<int>> checkBoard(rowSize, vector<int>(colSize, 0));
    return SearchingWord(0, 0, rowSize, colSize, board, word, checkBoard);
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "CCFDA";
    std::cout << "Word " << word << " present: " << WordSearch(board, word);
    return 0;
}