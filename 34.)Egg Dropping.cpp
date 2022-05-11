
 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    
    int eggDrop(int e, int f) 
    {
        // your code here
        static int flag=0;
        if(flag==0)
        {
            memset(dp,-1,sizeof(dp));
            flag++;
        }
        
        if(f==0||f==1)
        return f;
        if(e==1)
        return f;
        if(dp[e][f]!=-1)
        return dp[e][f];
        int mn=INT_MAX;
        for(int i=1;i<f;i++){
            int temp=1+max(eggDrop(e-1,i-1),eggDrop(e,f-i));
            mn=min(mn,temp);
        }
        return dp[e][f]= mn;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
