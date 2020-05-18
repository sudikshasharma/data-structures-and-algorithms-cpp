/*
	Cpp program to find maximum sum of subarrays of given array and print the subarray as well
	(Optimized program , with Time complexity O(n^2) using cumulative sum)
*/


#include<iostream>
#include<climits>

int main()
{
	int *a,num,size,*cumlSum,maxSum=INT_MIN,s,e;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	cumlSum=new int[size]{0};
	std::cout<<std::endl<<"Enter array elements : ";
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
		if(i!=0)
		{
            cumlSum[i]=a[i]+cumlSum[i-1];	//Cumulative sum
		}
	}
	for(int i=0;i<size;i++)
	{
	    for(int j=i;j<size;j++)
	    {
	        if(maxSum<(cumlSum[j]-cumlSum[i]))
	        {
	            maxSum=cumlSum[j]-cumlSum[i-1];
	            std::cout<<"i: "<<i<<" j: "<<j<<" maxSum: "<<maxSum<<std::endl;
	            s=i;
	            e=j;
	        }
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