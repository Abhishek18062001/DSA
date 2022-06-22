//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B){
        stack<int>st;
        st.push(-1);
        int j=0;
        for(int i=0;i<n;i++){
            st.push(A[i]);
            
                while(st.top()==B[j]&&j<n){
                st.pop();
                j++;
            }
                
            
        }
        if(st.size()==1)
        return 1;
        else
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
