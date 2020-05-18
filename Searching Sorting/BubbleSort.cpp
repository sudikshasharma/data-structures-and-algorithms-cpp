/*
	Cpp program to perform Bubble Sort
*/


#include<iostream>

void BubbleSort(int *a,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                std::swap(a[j],a[j+1]);
            }
        }
    }
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
	BubbleSort(a,size);
	std::cout<<std::endl<<"Sorted array : "<<std::endl;
	for(int i=0;i<size;i++)
	{
	    std::cout<<a[i];
	}
	return 0;
}