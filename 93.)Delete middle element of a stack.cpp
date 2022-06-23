//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s,int n){
      if(s.size()==n){
      s.pop();
      return;
      }int x=s.top();
      s.pop();
      solve(s,n);
      s.push(x);
    }
    void deleteMid(stack<int>&s, int n)
    {
        
        int num =s.top();
        if(n%2==0)
        n=n/2;
        else{
        n=n/2;
        n++;
        }
        solve(s,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends
