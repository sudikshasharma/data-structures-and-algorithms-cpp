/*

    Cpp program to remove consecutive duplicates from the string

*/
#include<iostream>
#include<string.h>

int main() 
{
	int length=1000,i;
	char *str = new char[length];
	std::cout<<"Enter string : ";
	std::cin.getline(str,length);
	for(i=1;i<strlen(str);i++)
	{
	  if(str[i]==str[i-1])
	  {
	      str[i]=str[i+1];
	  }
	}
	std::cout<<std::endl<<"After removing duplicates, string : "<<str;
	return 0;
}
