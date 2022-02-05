/*

Given a set of numbers. Print all the unique (non repeating) subsets created using the given numbers in sorted order

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> GetSubsets(vector<int> nums, vector<int> tempVec, vector<vector<int>> currentVec, bool isIncluding = true, int prevNum = -1)
{
    if (nums.size() == 0)
    {
        currentVec.push_back(tempVec);
        return currentVec;
    }
    int currenNum = nums[0];
    if (tempVec.size() > 0)
        prevNum = tempVec[tempVec.size() - 1];
    tempVec.push_back(currenNum);
    nums.erase(nums.begin());
    currentVec = GetSubsets(nums, tempVec, currentVec, true, prevNum);
    tempVec.erase(tempVec.end() - 1);
    if (prevNum != currenNum)
        currentVec = GetSubsets(nums, tempVec, currentVec, false, prevNum);
    return currentVec;
}

vector<vector<int>> UniqueSubsets(vector<int> nums)
{
    vector<int> tempVec;
    vector<vector<int>> currentVec;
    sort(nums.begin(), nums.end());
    currentVec = GetSubsets(nums, tempVec, currentVec);
    sort(currentVec.begin(), currentVec.end());
    return currentVec;
}

void PrintUniqueSubsets(vector<vector<int>> numSet)
{
    for (int i = 0; i < numSet.size(); i++)
    {
        for (int j = 0; j < numSet[i].size(); j++)
        {
            std::cout << " " << numSet[i][j];
        }
        std::cout << std::endl;
    }
}

int main()
{
    vector<vector<int>> numSet;
    vector<int> set = {1, 1, 5, 3};
    std::cout << "Unique Subsets: " << std::endl;
    numSet = UniqueSubsets(set);
    PrintUniqueSubsets(numSet);
    return 0;
}