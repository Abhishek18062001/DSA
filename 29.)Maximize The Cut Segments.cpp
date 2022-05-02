


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int sum, int x, int y, int z)
    {
        //Your code here
        int dp[4][sum+1];
        int arr[3];
        arr[0]=x;
        arr[1]=y;
        arr[2]=z;
      //  sort(arr,arr+3);
        int i,j,n=3;
        for(i=0;i<4;i++)
        dp[i][0]=INT_MIN;
        for(j=0;j<=sum;j++)
        dp[0][j]=-1;
       
        for(i=1;i<4;i++){
            for(j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i][j-arr[i-1]]+1);
              }  else{
                dp[i][j]=dp[i-1][j];
            }
            }
        }
        
       if(dp[3][sum]<0)
       return 0;
    
        return dp[3][sum];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
