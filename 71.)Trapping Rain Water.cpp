#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int left[n],right[n];
        left[0]=arr[0];
        int m=arr[0];
        right[n-1]=arr[n-1];
        for(int i=0;i<n;i++){
            left[i]=max(m,arr[i]);
            m=max(m,arr[i]);
        }
        m=arr[n-1];
        for(int i=n-1;i>=0;i--){
            right[i]=max(m,arr[i]);
            m=max(m,arr[i]);
            
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+min(left[i],right[i])-arr[i];
        }
    //    cout<<ans;
        return ans;
    }
    
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
