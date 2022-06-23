#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n=s.size(),ans=0;
    if(n%2==1)
    return -1;
    stack<char>st;
    for(int i=0;i<n;i++){
        if(st.empty()&&s[i]=='}'){
            ans++;
            st.push('{');
        }else{
            if(s[i]=='}')
            st.pop();
            else
            st.push('{');
        }
    }
    int x=st.size();
  //  cout<<x<<" "<<ans;
    x=x/2;
    ans=ans+x;
    return ans;
}
