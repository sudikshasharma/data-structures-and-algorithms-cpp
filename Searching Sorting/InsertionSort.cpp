/*
	Cpp program to perform Insertion Sort
*/


#include<iostream>

void InsertionSort(int *a,int size)
{
    int val;
    for(int i=1;i<size;i++)
    {
        val=a[i];
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>=val)
            {
                a[j+1]=a[j];
                if(j==0)
                {
                    a[j]=val;
                }
            }
            else
            {
                a[j+1]=val;
                break;
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
	InsertionSort(a,size);
	std::cout<<std::endl<<"Sorted array : "<<std::endl;
	for(int i=0;i<size;i++)
	{
	    std::cout<<a[i];
	}
	return 0;
}