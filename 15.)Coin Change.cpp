#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int arr[], int n, int sum) {

        // code here.
        int i,j;
        long long int dp[n+1][sum+1];
        for(i=0;i<=sum+1;i++){
            dp[0][i]=0;
        }
        for(i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=sum;j++){
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
