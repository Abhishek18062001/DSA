/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
 
  
  int i,j;
int lcs(string s1,string s2, int n,int m){
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(j=0;i<=m;j++)
    {
        dp[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
  return dp[n][m];
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.length();
    int m=s2.length();

    cout<<lcs(s1,s2,n,m)<<endl;

    return 0;
}
