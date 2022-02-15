#include <bits/stdc++.h>
#define ll long long int 
#define endl "\n"
#define pb push_back
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);
#define fastio1() cin.tie(NULL);
using namespace std;
struct trie{
    bool isend=false ;
    
    trie *child[26];
    trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
     
};
void insert(trie *root,string s,int key){
    trie *curr=root;
    for(int i=0;i<26;i++){
        
        int index=s[i]-'a';
        if(curr->child[index]==NULL){
        curr->child[index] = new trie ();
            curr=curr->child[index];
        }
    }
    curr->isend=true;
}
bool search (trie * root, string s)
{
  trie *curr = root;
  for (int i = 0; i < s.size (); i++)
    {
      int index = s[i] - 'a';
      if (curr->child[index] == NULL)
	return false;
      curr = curr->child[index];
    }
 return curr->isend;
}

int main() {
	fastio();
    fastio1();
	ll t=1;
	//cin>>t;
	while(t--)
	{
	 string arr[]={"rat","cat","bat"};
	 trie *root=new trie();
	 
	 int key=sizeof(arr)/sizeof(arr[0]);
	 for(int i=0;i<key;i++){
	 insert(root,arr[i],key);
	 for (int i = 0; i < key; i++)
    {
      bool check= search (root, arr[i]);
      cout<<check<<" ";
    }
	 for(int i=0;i<key;i++){
	 bool check=search(root,"avbc");
	 cout<<check<<endl;
	 }
	 }  
	}
	return 0;
}
