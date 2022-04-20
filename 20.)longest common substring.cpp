#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        // your code here
        long long int dp[n+1][m+1],i,j;
        for(i=0;i<=n;i++)
        dp[i][0]=0;
         for(i=0;i<=m;i++)
        dp[0][i]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=0;
            }
        }
        long long int a=0;
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                if(dp[i][j]>a)
                a=dp[i][j];
                
            }
           // cout<<endl;
        }
        return a;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
