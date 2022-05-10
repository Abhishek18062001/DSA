// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

long long int mod=1e9+7;
    int nCr(int n, int r){
        
        // code here
             vector<int>arr(n,1);
             long long int dp[n+1][r+1];
        int i,j;
        if(r>n)
        return 0;
        if(r==n)
        return 1;
        for(i=0;i<n+1;i++){
            for(j=0;j<r+1;j++){
                if(j==0)
                dp[i][j]=1;
                else
                dp[i][j]=0;
                
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=r;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-arr[i-1]]%mod+dp[i-1][j]%mod)%mod;
                }else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=r;j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
