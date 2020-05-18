/*
	Cpp program to perform Bubble Sort with Comparator	(Using a compare function and passing its name as parameter to other(BubbleSort) function)
*/


#include<iostream>

bool Compare(int a, int b)
{
	return a>b;
}

void BubbleSort(int *a,int size, bool (&compr)(int a,int b))	// Passing function name as parameter
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(compr(a[j],a[j+1]))	//for sorting in descending order =>   if(compr(a[j+1],a[j]))
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
	BubbleSort(a,size,Compare);	// Pass function name as parameter 
	std::cout<<std::endl<<"Sorted array : "<<std::endl;
	for(int i=0;i<size;i++)
	{
	    std::cout<<a[i];
	}
	return 0;
}