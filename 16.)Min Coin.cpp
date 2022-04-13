#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int arr[], int n, int sum) 
	{ 
	    // Your code goes here
	    long long int dp[n+1][sum+1];
	    int i,j;
	    for(i=0;i<=n;i++)
	    dp[i][0]=0;
	    for(i=0;i<=sum;i++)
	    dp[0][i]=INT_MAX-1;
	    
	    for(j=1;j<=sum;j++){
	        if(j%arr[0]==0)
	        dp[1][j]=j/arr[0];
	        else
	        dp[1][j]=INT_MAX-1;
	        
	    }
	    for(i=2;i<=n;i++){
	        for(j=1;j<=sum;j++){
	            if(arr[i-1]<=j)
	            dp[i][j]=min(dp[i-1][j],dp[i][j-arr[i-1]]+1);
	            else
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	   // for(i=0;i<=n;i++){
	   //     for(j=0;j<=sum;j++){
	   //     cout<<dp[i][j]<<" ";
	   //   }  cout<<endl;
	   // }
	   if(dp[n][sum]==INT_MAX-1)
	   return -1;
	    return dp[n][sum];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
