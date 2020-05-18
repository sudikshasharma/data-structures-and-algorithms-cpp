/*
	Cpp program to print the max profit by selling wines such that, an array contains wines with rates.
	It must be sold in the pattern that one wine is sold per yer at either end of the wine array.
	The cost of each wine per year will increment. So, sell wine bottles in the sequence to generate max
	profit with respect to yearly increment in price.
    [2D DP question as we've 2 changing variables, wines and year]
*/

#include<iostream>

int Wine_TD(int *a, int **dp,int i,int j,int yr)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    int op1 = (a[i]*yr)+Wine_TD(a,dp,i+1,j,yr+1);
    int op2 = (a[j]*yr)+Wine_TD(a,dp,i,j-1,yr+1);
    return dp[i][j]=std::max(op1,op2);
}

int Wine_BU(int *a, int arraySize)
{
    int **dp = new int *[arraySize+1]{0},yr=arraySize,jCount=0;
    for(int i=0;i< arraySize;i++)
    {
        dp[i] = new int[arraySize+1]{0};
    }
    for(int i=0;i<arraySize;i++)
    {
        int startIndex=0,endIndex=arraySize-i,j=jCount;
        while(startIndex<endIndex)
        {
            if(startIndex==j)
            {
                dp[startIndex][j]=yr*a[startIndex];
            }
            else
            {
                dp[startIndex][j]=yr*a[startIndex]+std::max(dp[startIndex][j-1],dp[startIndex+1][j]);
            }
            j++;
            startIndex++;
        }
        yr--;
        jCount++;
    }
    return dp[0][arraySize-1];
}


int main()
{
	int n,*a,**dp,maxProfit=0;
	std::cout<<"Enter number of wines : ";
	std::cin>>n;
	std::cout<<"Enter wine rates : "<<std::endl;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
	    std::cin>>a[i];
	}
	dp=new int*[n+1];
	for(int i=0;i<n;i++)
	{
	    dp[i]=new int[n+1]{0};
	}
	// DP Top-Down recursive approach
	maxProfit =Wine_TD(a,dp,0,n-1,1);
	std::cout<<"Max Profit (DP Top-Down approach) : "<<maxProfit<<std::endl;	
	// DP Bottom-UP iterative approach
	maxProfit =Wine_BU(a,n);
	std::cout<<"Max Profit (DP Bottom-Up approach) : "<<maxProfit<<std::endl;		
	return 0;
}