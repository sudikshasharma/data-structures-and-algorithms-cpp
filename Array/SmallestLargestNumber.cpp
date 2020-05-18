/*
	Cpp program to find smallest and largest number in an array.
*/

#include<iostream>
#include<climits>

int main()
{
	int *a,num,size,small,large;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	std::cout<<std::endl<<"Enter array elements : ";
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
	}
	small=INT_MAX;
	large=INT_MIN;
	for(int i=0;i<size;i++)
	{
	    small=std::min(small,a[i]);
	    large=std::max(large,a[i]);
	}
	std::cout<<std::endl<<"Smallest number : "<<small<<" Largest number : "<<large;
	return 0;
}