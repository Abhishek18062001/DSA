//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool check(vector<vector<int>>&M,int first,int second ){
        if(M[first][second]==1)
        return 1;
        else
        return 0;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(check(M,first,second)){
                st.push(second);
            }else{
                st.push(first);
            }
        }
        
        
        int ans=st.top();
        //cout<<ans;
        int r=0,c=0;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0)
            r++;
        }
        for(int i=0;i<n;i++){
            if(M[i][ans]==1)
            c++;
        }
        if(r==n&&c==n-1)
        return ans;
        else
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
