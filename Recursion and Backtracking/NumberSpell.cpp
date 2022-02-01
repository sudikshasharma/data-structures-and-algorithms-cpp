/*

Given a number like 2021, convert into string like "two zero two one" recursively

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> numberString = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void NumberSpell(int num)
{
    if (num == 0)
        return;
    int rem = num % 10;
    NumberSpell(num / 10);
    std::cout << numberString[rem] << " ";
}

int main()
{
    int num = 209821;
    std::cout << "Given Number : " << num;
    std::cout << std::endl
              << "Number Spelled : ";
    NumberSpell(num);
    return 0;
}