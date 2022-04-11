//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
                           
    bool isSubsetSum(vector<int>arr, int sum){
         int n=arr.size(),i,j;
     //    cout<<n<<endl;
     bool dp[n+1][sum+1]; 
       
         int flag=0;
        if(flag==0){
           
            memset(dp,false,sizeof(dp));
            flag++;
        }
    for ( i = 0; i <n+1; i++)
        dp[i][0] = true;
 
    
    for ( i = 1; i < sum+1; i++)
        dp[0][i] = false;
        
        for(i=1;i<n+1;i++){
            for(j=1;j<sum+1;j++){
                if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        // for(i=0;i<n+1;i++){
        //     for(j=0;j<sum+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
     return dp[n][sum];   
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
