/*

Given a set of numbers and a variable sum. Return true if there exist a subset of numbers whose sum is equal to the
given variable sum.

For example,

Input:
array = -1,2,3,4
sum = 5

Output:
true

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool GetSubsets(vector<int> nums, vector<int> tempVec, int curSum, int sum, bool isIncluding = true, int prevNum = -1)
{
    bool status;
    if (nums.size() == 0)
    {
        return false;
    }
    int currenNum = nums[0];
    if (tempVec.size() > 0)
        prevNum = tempVec[tempVec.size() - 1];
    tempVec.push_back(currenNum);
    curSum += currenNum;
    if (curSum == sum)
        status = true;
    nums.erase(nums.begin());
    if (!status)
        status = GetSubsets(nums, tempVec, curSum, sum, true, prevNum);
    tempVec.erase(tempVec.end() - 1);
    curSum -= currenNum;
    if (prevNum != currenNum && !status) ///////////This is done to avoid any extra computation in case the vector of numbers has repeating numbers
        status = GetSubsets(nums, tempVec, curSum, sum, false, prevNum);
    return status;
}

bool IsEqualToSum(vector<int> nums, int sum)
{
    vector<int> tempVec;
    vector<vector<int>> currentVec;
    sort(nums.begin(), nums.end());
    return GetSubsets(nums, tempVec, 0, sum);
}

int main()
{
    vector<int> set = {-2, 4, 2, 5};
    int sum = 3;
    // Print 1 for true and 0 for false
    std::cout << "Does any subset's sum of the given numbers equal to " << sum << " : " << IsEqualToSum(set, sum);
    return 0;
}