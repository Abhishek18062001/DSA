#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    int m=n,i,j;
		    string x=str;
		    string y=str;
		    int dp[n+1][m+1];
		    for(i=0;i<=n;i++)
		    dp[i][0]=0;
		    for(i=0;i<=m;i++)
		    dp[0][i]=0;
		    for(i=1;i<=n;i++){
		        for(j=1;j<=m;j++){
		            if(x[i-1]==y[j-1]&&i!=j)
		            dp[i][j]=1+dp[i-1][j-1];
		            else
		            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            
		        }
		    }
		    return dp[n][m];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
