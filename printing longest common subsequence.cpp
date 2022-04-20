/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
     string v="";
  string x,y;
  int n,m,i,j;
  cin>>n>>m;
  cin>>x>>y;
  int dp[n+1][m+1];
  for(i=0;i<=n;i++){
      dp[i][0]=0;
  }
  for(i=0;i<=m;i++){
      dp[0][i]=0;
  }
  for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
          if(x[i-1]==y[j-1])
          dp[i][j]=1+dp[i-1][j-1];
          else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
  }
//   for(i=0;i<=n;i++){
//       for(j=0;j<=m;j++){
//           cout<<dp[i][j]<<" ";
//       }
//       cout<<endl;
//   }
    i=n;
    j=m;
   
    while(i>0&&j>0){
        if(x[i-1]==y[j-1]){
          v.push_back(x[i-1]);
          i--;
          j--;
            
        }else{
          
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
            
        }
        
    }
    cout<<v;
    cout<<endl;
    return 0;
}
