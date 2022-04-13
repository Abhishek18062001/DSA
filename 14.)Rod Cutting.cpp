// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        int dp[n+1][n+1];
        int i,j;
        int arr[n];
        memset(arr,0,sizeof(arr));
        for(i=0;i<n;i++)
        arr[i]=i+1;
        for(i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(i=0;i<=n;i++)
        dp[i][0]=1;
        
        for(i=1;i<=n;i++){
            for(j=0;j<=n;j++){
                if(arr[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-arr[i-1]]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
    // for(i=0;i<=n;i++){
    //     for(j=0;j<=n;j++){
    //     cout<<dp[i][j]<<" ";
    // }
    // cout<<endl;
    // }
    return dp[n][n]-1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
