/*
	Cpp program to find the pair in SORTED array with the sum equal to the given sum (Two pointer approach used)
*/


#include<iostream>

int main()
{
	int *a,num,size,givenSum;
	std::cout<<"Enter number of array elements : ";
	std::cin>>size;
	a=new int[size]();
	std::cout<<std::endl<<"Enter array elements : ";    //Sorted array
	for(int i=0;i<size;i++)
	{
		std::cin>>a[i];
	}
	std::cout<<std::endl<<"Enter pair sum : ";
	std::cin>>givenSum;
	for(int i=0,j=size-1;i<j;)
	{
        if(givenSum<(a[i]+a[j]))
        {
            j--;
        }
        else if(givenSum>(a[i]+a[j]))
        {
            i++;
        }
        else
        {
            std::cout<<std::endl<<"Number pair Found..numbers : "<<a[i]<<" , "<<a[j];
            return 0;
        }
	}
	std::cout<<std::endl<<"Pair not found";
	return 0;
}