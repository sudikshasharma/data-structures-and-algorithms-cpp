/*

Given a stream of characters and we have to find first non repeating character each time a
character is inserted to the stream.

Examples:
Input  : a a b c
Output : a 0 b b

Input  : a a c
Output : a 0 c

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> FirstNonRepeating(vector<char> str)
{
    queue<char> qu;
    qu.push(str[0]);

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1] || (str[i - 1] == '0' && str[i] == qu.front()))
        {
            if (i < str.size() - 1 && str[i + 1] != qu.front())
                qu.pop();
            str[i] = '0';
        }
        else if (str[i] == qu.front())
        {
            qu.pop();
            str[i] = qu.front();
        }
        else if (str[i] != str[i - 1] && str[i - 1] != '0')
        {
            if (str[i] != qu.back())
                qu.push(str[i]);
            str[i] = str[i - 1];
        }
    }
    return str;
}

void print(vector<char> str)
{
    for (int i = 0; i < str.size(); i++)
    {
        std::cout << str[i];
    }
}

int main()
{
    vector<char> str = {'a', 'a', 'a', 'c', 'c'};
    std::cout << std::endl
              << "Given String : ";
    print(str);
    str = FirstNonRepeating(str);
    std::cout << std::endl
              << "String after processing repeating characters : ";
    print(str);
    return 0;
}
