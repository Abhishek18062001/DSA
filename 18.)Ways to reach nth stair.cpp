#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        long long int dp[n+1],i;
        long long int m=1e9+7;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(i=3;i<=n;i++){
            dp[i]=(dp[i-1]%m+dp[i-2]%m)%m;
        }
        return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends
