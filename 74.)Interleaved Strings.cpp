//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        int x=a.size();
        int y=b.size();
        int z=c.size();
        bool dp[x+1][y+1];
        memset(&dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++){
                if(i==0||j==0)
                dp[i][j]=true;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(a[i-1]==c[i+j-1])
                dp[i][j]|=dp[i-1][j];
                if(b[j-1]==c[i+j-1])
                dp[i][j]|=dp[i][j-1];
                
            }
        }
        return dp[x][y];
        
        
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
