//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string x) {
        //code here
        int n=x.length();
        string y;
        y=x;
        reverse(x.begin(),x.end());
        int m=n,i,j;
        int dp[n+1][m+1];
        for(i=0;i<=n;i++)
        dp[i][0]=0;
        for(i=0;i<=m;i++)
        dp[0][i]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
