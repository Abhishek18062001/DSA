//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string x){
    //complete the function here
    string y=x;
    reverse(y.begin(),y.end());
    int n=x.length();
    int m=n,i,j;
    int dp[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][m];
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
