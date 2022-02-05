/*

Given a dictionary words in a variable named board and a string in the variable word.
Print the no. of ways the word can be broken using the words in the given dictionary.
For example, words in dictionary : "i","love","sam","sung","samsung","mobile"
word : "ilovesamsungmobile"
Possible ways to break the word : "i love sam sung mobile", "i love samsung mobile"
Thus, Expected Output : 2

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int GetWordCombinations(int currentIndex, string str, vector<string> &dictionary)
{
    int count = 0;
    if (str.length() == 0)
        return 1;
    if (currentIndex == dictionary.size())
        return 0;
    int startIndex = str.find(dictionary[currentIndex]);
    if (startIndex != -1)
    {
        str.erase(startIndex, dictionary[currentIndex].size());
        count += GetWordCombinations(currentIndex, str, dictionary);
        str.insert(startIndex, dictionary[currentIndex]);
    }
    count += GetWordCombinations(currentIndex + 1, str, dictionary);
    return count;
}

int WordBreak(string str, vector<string> &dictionary)
{
    return GetWordCombinations(0, str, dictionary);
}

int main()
{
    vector<string> board = {{"apple"},
                            {"pen"},
                            {"applepen"},
                            {"pine"},
                            {"pineapple"}};
    string word = "pineapplepenapple";
    std::cout << "Given word : " << word;
    std::cout << std::endl
              << "No. of combinations present : " << WordBreak(word, board);
    return 0;
}