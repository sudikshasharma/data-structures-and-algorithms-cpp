/*

    Cpp program to check if the string is palindrome

*/
#include<iostream>
#include<string.h>

int main() 
{
	int length=1000;
	char *str = new char[length];
	std::cout<<"Enter string : ";
	std::cin>>str;
	for(int i=0,j=strlen(str)-1;i<j;i++,j--)
	{
	    if(str[i]!=str[j])
	    {
	        std::cout<<std::endl<<"String is not Palindrome !";
	        return 0;
	    }
	}
	std::cout<<std::endl<<"String is Palindrome !";
	return 0;
}