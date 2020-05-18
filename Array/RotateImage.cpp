/*
	
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 
Explanation
Rotate the array 90 degrees anticlockwise.

*/


#include<iostream>

void Swap(int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void Reverse(int **a, int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0,j=n-1;i<j;i++,j--)
		{
			Swap(&a[k][i],&a[k][j]);
		}
		
	}
}

void Transpose(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			Swap(&a[i][j],&a[j][i]);
		}
	}
}

void Print(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

int main() 
{
	int n,**a;
	std::cin>>n;
	a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			std::cin>>a[i][j];
		}
	}
	Reverse(a,n);
	Transpose(a,n);
	Print(a,n);
	return 0;
}