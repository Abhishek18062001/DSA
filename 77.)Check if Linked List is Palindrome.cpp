#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int count=0;
        Node* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            count++;
        }
        int o=0;
        if(count%2==1)
        o++;
        count=count/2;
       // cout<<count;
        fast=head;
        while(count--){
            fast=fast->next;
        }
        if(o)
        fast=fast->next;
        
    
        //cout<<fast->data;
        Node* slow=head;
        stack<int>st;
        while(fast!=NULL){
            st.push(fast->data);
            fast=fast->next;
        }
        while(!st.empty()){
            int curr=st.top();
            if(curr!=slow->data)
            return 0;
            slow=slow->next;
            st.pop();
        }
        return 1;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
