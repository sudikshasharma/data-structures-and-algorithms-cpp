/*

    Cpp program to divide string into tokes(substrings) on the basis of any deliminator(symbol)
    *Alternative of strtok() of C++ stl

    e.g. String = "abc;def;ghi", deliminator = ';'
    then, tokens are : abc
                       def
                       ghi

*/

#include <iostream>
#include <string.h>

char *strtok(char *str, char delim)
{
    static char *stringHead = NULL;
    if (str != NULL)
    {
        stringHead = str;
    }
    if (stringHead == NULL)
    {
        return NULL;
    }
    int i = 0;
    char *outputString = new char[strlen(stringHead) + 1];
    for (; stringHead[i] != '\0'; i++)
    {
        if (stringHead[i] != delim)
        {
            outputString[i] = stringHead[i];
        }
        else
        {
            stringHead[i] = '\0';
            stringHead = stringHead + i + 1;
            return outputString;
        }
    }
    outputString[i] = '\0';
    stringHead = NULL;
    return outputString;
}

int main()
{
    char delim, length = 1000;
    char *str = new char[length], *ptr;
    std::cout << "Enter string : ";
    std::cin.getline(str, length);
    std::cout << "Enter deliminator to separate string : ";
    std::cin >> delim;
    std::cout << std::endl
              << "After tokenization, tokens : " << std::endl;
    ptr = strtok(str, delim);
    std::cout << ptr << std::endl;
    while (ptr != NULL)
    {
        ptr = strtok(NULL, delim);
        std::cout << ptr << std::endl;
    }
    return 0;
}
