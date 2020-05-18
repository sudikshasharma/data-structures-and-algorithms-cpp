/*
	Cpp program to find maximum sum of subarrays of given array and print the subarray as well
*/


#include<iostream>
#include<climits>

int main()
{
	int *a,num,size,sum=0,maxSum=INT_MIN,s,e;
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
	    for(int j=i;j<size;j++)
	    {
	      for(int k = i;k<=j;k++)
	      {
	        sum+=a[k];
	      }
	      if(sum > maxSum)
	      {
	      	maxSum = sum;
	      	s=i;
	      	e=j;
	      }
	      sum=0;
	    }
	}
	std::cout<<std::endl<<"Maximum sum : "<<maxSum;
	std::cout<<std::endl<<"Subarray with maximum sum : ";
	for(int i=s;i<=e;i++)
	{
		std::cout<<a[i]<<" ,";
	}
	return 0;
}