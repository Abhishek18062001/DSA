// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int dp[1001][1001];
    bool isplain(string str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j])
                return false;
                 i++;
                j--;
                
            
        }
        return true;
    }
   
    int solve(string s,int i,int j){
        if(dp[i][j]!=-1){
        return dp[i][j];
        }
        if(i>=j||isplain(s,i,j)){
        dp[i][j]=0;
        return dp[i][j];
        }
    
         int ans =INT_MAX;
         int left ,right;
        for(int k=i;k<=j-1;k++){
            if(dp[i][k]!=-1)
            {
                left=dp[i][k];
            }else{
                left=solve(s,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }else{
                right=solve(s,k+1,j);
                dp[k+1][j]=right;
            }
           dp[i][j]=left +right +1;
            ans =min(ans,dp[i][j]);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    { 
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
  
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
