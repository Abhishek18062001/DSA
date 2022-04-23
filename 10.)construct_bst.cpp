#include <bits/stdc++.h>
#define ll long long int 
#define endl "\n"
#define pb push_back
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);
#define fastio1() cin.tie(NULL);
using namespace std;
 
 struct tree{
   int data; 
   tree *left,*right;
     tree(int n){
       data=n;
       left=right=NULL;
   }
   
 };
 void inorder(tree *root){
     if(root!=NULL){
         inorder(root->left);
         cout<<root->data<<": ";
         inorder(root->right);
     }
     return;
 }
   tree * bst(tree *root,int a[],int start,int end){
       if(start>end)
       return NULL;
       int mid =(start+end)/2;
        root= new tree(a[mid]);
       root->left= bst(root,a,start,mid-1);
       root->right= bst(root,a,mid+1,end);
       return root; 
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
	   sort(a,a+n);
	 
	   
	   tree *root;
	   
	   
	   root=bst(root,a,0,n-1);
	   inorder(root);
	}
	return 0;
}
