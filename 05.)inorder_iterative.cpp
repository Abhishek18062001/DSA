#include <bits/stdc++.h>
#define ll long long int 
#define endl "\n"
#define pb push_back
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);
#define fastio1() cin.tie(NULL);
using namespace std;
struct Node{
    int data;
    Node *right ,*left;
    Node(int d){
        data =d;
        right = left =NULL;
    }
      
};
Node *construct(Node *root, int a[], int n){
    queue <Node* > q;
    q.push(root);
    Node *curr;
    int i=1;
    while ( q.empty()==false){
        curr=q.front();
        if(i<n)
        curr->left=new Node(a[i++]);
        if(i<n)
        curr->right=new Node(a[i++]);
        
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
        
        q.pop();
    }
    return root;
}
void inorder(Node *root){
    stack <Node *> s;
    Node *curr=root;
    while(curr!=NULL|| s.empty()==false){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
            
        }
        
           curr=s.top();
           cout<<curr->data;
           s.pop();
           curr=curr->right;
        
        
    }
}

int main() {
	fastio();
    fastio1();
	ll t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;	
	    int a[n],i;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    Node *node=new Node(a[0]);
	    construct(node,a,n);
	    
	    inorder(node);
	}
	return 0;
}
