/*
	Cpp program to generate subarrays of given array
*/


#include<iostream>


int main()
{
	int *a,num,size;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	std::cout<<std::endl<<"Enter array elements : ";
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
	}
	std::cout<<std::endl<<"Subarrays are : "<<std::endl;
	for(int i=0;i<size;i++)
	{
	    for(int j=i;j<size;j++)
	    {
	      for(int k = i;k<=j;k++)
	      {
	          std::cout<<a[k]<<" , ";
	      }
	      std::cout<<std::endl;
	    }
	}
	return 0;
}