#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum=sum+arr[i];
	    }
	    bool dp[n+1][sum+1];
	    int i,j;
	    memset(dp,false,sizeof(dp));
	    for(int i=0;i<sum+1;i++)
	    dp[0][i]=false;
	    for(int i=0;i<n+1;i++)
	    dp[i][0]=true;
	    
	    for(i=1;i<=n;i++){
	        for(j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	            }
	                else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	   // for(i=0;i<=n;i++){
	   //     for(j=0;j<=sum;j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    int ans=0;
	   // cout<<sum/2<<" "<<dp[n][sum/2]<<" ";
	    for(j=(sum+1)/2;j>=0;j--){
	        if(dp[n][j]==1)
	        ans=max(ans,j);
	    }
	  //  cout<<sum<<" "<<ans;
	    int ans1=sum-(2*ans);
	    return abs(ans1);
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
