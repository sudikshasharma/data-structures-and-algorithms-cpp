/*
	Cpp program to print minimum steps taken to convert given number to 1 using any one below mentioned operation at each step.
	Operations:
	n=n/2, if n%2==0
	n=n/3, if n%3==0
	n=n-1
*/

#include<iostream>
#include<climits>

int MinSteps_TD(int n, int *dp)
{
	if(n == 1)
	{
		return 0;
	}
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
	if(n%2==0)
	{
		op1 = 1+MinSteps_TD(n/2,dp);
	}
	if(n%3==0)
	{
		op2 = 1+MinSteps_TD(n/3,dp);
	}
		op3 = 1+MinSteps_TD(n-1,dp);
		return dp[n] = std::min(std::min(op1,op2),op3);
}

int MinSteps_BU(int n)
{
	int *dp = new int[n+1]{0},op1,op2,op3;
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		op1=op2=op3=INT_MAX;
		if(i%2==0)
		{
			op1=1+dp[i/2];
		}
		if(i%3==0)
		{
			op2=1+dp[i/3];
		}
			op3=dp[i-1];
		dp[i]=std::min(std::min(op1,op2),op3);
	}
	return dp[n];
}


int main()
{
	int n,*dp,steps;
	std::cout<<"Enter number : ";
	std::cin>>n;
	dp=new int[n+1];
	// DP Top-Down recursive approach
	steps =MinSteps_TD(n,dp);
	std::cout<<"Minimum Steps (DP Top-Down approach) : "<<steps<<std::endl;		// Space complexity = O(n), TimeComplexity = O(n)
	// DP Bottom-Up iterative approach
	steps =MinSteps_BU(n);
	std::cout<<"Minimum Steps (DP Bottom-Up approach) : "<<steps<<std::endl;		// Space complexity = O(n), TimeComplexity = O(n)
	return 0;
}