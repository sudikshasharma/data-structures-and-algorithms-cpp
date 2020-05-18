/*
	Cpp program to print minimum coins of given type required to make a change of given number
	Types of coins are stored in an array and any type can be used infinete number of times
*/

#include<iostream>
#include<climits>

int MinCoin_TD(int *a, int *dp, int num, int arraySize)
{
    if(num==0)
    {
        return 0;
    }
    if(dp[num]!=0)
    {
        return dp[num];
    }
    int coinCount = INT_MAX;
	for(int i=0;i<arraySize;i++)
	{
	    if(num>=a[i])
	    coinCount = 1+std::min(coinCount,MinCoin_TD(a,dp,num-a[i],arraySize));
	}
	return dp[num]=coinCount;
}

int MinCoin_BU(int *a, int num, int arraySize)
{
    int *dp=new int[num+1]();
    dp[0]=0;
    int coinCount = INT_MAX;
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<arraySize;j++)
        {
            if(a[j]<=i)
            {
                dp[i]=1+std::min(dp[i-a[j]],coinCount);
            }
        }
    }
    return dp[num];
}


int main()
{
	int num,*dp,coinCount,*coin,cointType;
	std::cout<<"Enter number of types of coins : ";
	std::cin>>cointType;
	coin=new int[cointType]();
	std::cout<<"Enter coin value : ";
	for(int i =0;i<cointType;i++)
	{
	    std::cin>>coin[i];
	}
	std::cout<<"Enter amount to generate change : ";
	std::cin>>num;
	dp=new int[num+1]();
	// DP Top-Down recursive approach
	coinCount =MinCoin_TD(coin,dp,num,cointType);
	std::cout<<"Minimum Coins (DP Top-Down approach) : "<<coinCount<<std::endl;		
	// DP Bottom-Up iterative approach
	coinCount =MinCoin_BU(coin,num,cointType);
 	std::cout<<"Minimum Coins (DP Bottom-Up approach) : "<<coinCount<<std::endl; 
	return 0;
}