#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


void solve(stack<int> &s,int num)
{
   if(s.empty())
   {
       s.push(num);
       return;
   }
   else if(num<s.top())
   {
       int ans=s.top();
       s.pop();
       solve(s,num);
       s.push(ans);
   }
   else
   {
       s.push(num);
   }
}

void SortedStack :: sort()
{
 
  if(s.empty())
   return;
   
   int num=s.top();
   s.pop();
   sort();


   solve(s,num);
}
