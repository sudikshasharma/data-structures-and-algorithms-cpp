/*
	Cpp program to perform Binary search
*/

// Array needs to be sorted

#include<iostream>
#include<climits>

int BinarySearch(int *a, int num,int size)
{
    int start=0,end=size-1,mid;
    while(start<end)
    {
        mid=(start+end)/2;
        if(a[mid]==num)
        {
            return mid+1;
        }
        if(a[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
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
	result=BinarySearch(a,num,size);
	if(result!=-1)
	{
	    std::cout<<std::endl<<"Element Found ! Index : "<<result;
	}
	else
	{
	    std::cout<<"Element not found !";
	}
	return 0;
}