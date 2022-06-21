#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long int>solve(long long int arr[],int n){
        stack<long long int>s;
        s.push(-1);
        vector<long long int>ans(n);
        for(int i=n-1;i>=0;i--){
            long long int curr=arr[i];
            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<long long int>solve1(long long int arr[],int n){
        stack<long long int>s;
        s.push(-1);
        vector<long long int>ans(n);
        for(int i=0;i<n;i++){
            long long int curr=arr[i];
            while(s.top()!=-1&&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long int>next(n);
        next=solve(arr,n);
        vector<long long int>prev(n);
        prev=solve1(arr,n);
        long long int area=INT_MIN;
        for(int i=0;i<n;i++){
            long long int l =arr[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            long long int b=next[i]-prev[i]-1;
            long long int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
