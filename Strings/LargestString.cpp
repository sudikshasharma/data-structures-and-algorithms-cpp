/*

    Cpp program to print the largest string and its length

*/
#include<iostream>
#include<string.h>

int main() 
{
	int length=1000,num;
	char *str = new char[length],*strMax=new char[length];
	std::cout<<"Enter number of strings : ";
	std::cin>>num;
	std::cin.get();
	std::cout<<std::endl<<"Enter strings : ";
	for(int i=0;i<num;i++)
	{
	    std::cin.getline(str,length);
	    if(strlen(str)>strlen(strMax))
	    {
	        strcpy(strMax,str);
	    }
	}
	std::cout<<std::endl<<"Largest string : "<<strMax<<std::endl<<"Length of largest string : "<<strlen(strMax);
	return 0;
}