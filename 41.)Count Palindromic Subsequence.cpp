// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int dp[1001][1001];
    long long int mod=1e9+7;
    long long int solve(string &s,int i,int j){
        if(i>j)
        return 0;
        if(i==j)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==s[j]){
          return   dp[i][j]=(1+solve(s,i+1,j)%mod+solve(s,i,j-1)%mod)%mod;
        }else{
        return     dp[i][j]=(mod+solve(s,i+1,j)%mod+solve(s,i,j-1)%mod-solve(s,i+1,j-1)%mod)%mod;
        }
        
    }
    long long int  countPS(string str)
    {
       //Your code here
       long long int n=str.length();
       memset(dp,-1,sizeof(dp));
     
       return solve(str,0,n-1);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
