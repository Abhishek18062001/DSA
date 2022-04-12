//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
     int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum=sum+nums[i];
        }
        if(sum<abs(target) || (sum+target)%2 != 0)
            return 0;
        int remain=(sum+target)/2;
        int t[n+1][remain+1];
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<remain+1;j++) {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++) {
		  for(int j=0;j<remain+1;j++) {
                if(nums[i-1]<=j) 
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][remain];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
