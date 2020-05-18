/*
	Cpp program to find maximum sum of subarrays of given array 
	(Optimized program , with Time complexity O(n) using Kadane's Algorithm)
*/


#include<iostream>

int main()
{
	int *a,num,size,maxSum=0,curSum=0;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	std::cout<<std::endl<<"Enter array elements : ";
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
	}
	for(int i=0;i<size;i++)
	{
	    if(i!=0 || a[i]>0)
	    {
	      curSum+=a[i];  
	    }
	    maxSum=std::max(curSum,maxSum);
	    std::cout<<"cur: "<<curSum<<" maxSum: "<<maxSum<<std::endl;
	}
	std::cout<<std::endl<<"Maximum sum : "<<maxSum;
	return 0;
}