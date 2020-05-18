/*
	Cpp program to perform Selection Sort
*/


#include<iostream>

void SelectionSort(int *a,int size)
{
    int min_index=0;
    for(int i=0;i<size;i++)
    {
        min_index=i;
        for(int j=i;j<size;j++)
        {
            if(a[min_index]>a[j])
            {
                min_index = j;
            }
        }
        std::swap(a[i],a[min_index]);
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
	SelectionSort(a,size);
	std::cout<<std::endl<<"Sorted array : "<<std::endl;
	for(int i=0;i<size;i++)
	{
	    std::cout<<a[i];
	}
	return 0;
}