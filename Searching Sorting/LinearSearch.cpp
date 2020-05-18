/*
	Cpp program to perform linear search on an array.
*/

#include<iostream>

int LinearSearch(int *a,int num,int size)
{
	for(int i=0;i<size;i++)
	{
		if(a[i]==num)
		{
			return i+1;
		}
	}
	return -1;
}

int main()
{
	int *a,num,size,result;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	std::cout<<std::endl<<"Enter array elements : ";
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
	}
	std::cout<<std::endl<<"Enter element to search : ";
	std::cin>>num;
	result = LinearSearch(a,num,size);
	if(result!=-1)
	{
		std::cout<<std::endl<<"Element Found! Index : "<<result;
	}
	else
	{
		std::cout<<std::endl<<"Element Not Found!";
	}
	return 0;
}