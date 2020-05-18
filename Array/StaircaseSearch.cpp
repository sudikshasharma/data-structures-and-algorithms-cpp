/*

	Cpp program to search element in row and column wise sorted array.

*/
#include<iostream>



void SearchArray(int **a,int key,int n,int m)
{
    int startIndexI=0,startIndexJ=m-1;
    while(startIndexI<m && startIndexJ>=0)
    {
        if(a[startIndexI][startIndexJ]==key)
        {
            std::cout<<"Number Found !! Index : "<<startIndexI<<" , "<<startIndexJ;
            return;
        }
        if(a[startIndexI][startIndexJ]<key)
        {
            startIndexI++;
        }
        else 
        {
            startIndexJ--;
        }

    }
    std::cout<<"Number Not Found !!";
}

int main() 
{
	int n,m,key,**a;
	std::cout<<"Enter number of rows : ";
	std::cin>>n;
	std::cout<<std::endl<<"Enter number of columns : ";
	std::cin>>m;
	a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
	}
	std::cout<<std::endl<<"Enter elements of array : ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			std::cin>>a[i][j];
		}
	}
	std::cin>>key;
	SearchArray(a,key,n,m);
	return 0;
}
