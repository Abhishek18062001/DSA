#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool solve(vector<int>adj[],int vis[],int node,int col[],int c){
        vis[node]=1;
        col[node]=c;
        for(int i=0;i<adj[node].size();i++){
            int child=adj[node][i];
            if(vis[child]==0){
                bool flag=solve(adj,vis,child,col,c^1);
                if(flag==0)
                return 0;
            }else{
                if(col[node]==col[child])
                return 0;
            }
        }
        return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int col[V],vis[V];
	    for(int i=0;i<V;i++){
	        vis[i]=0;
	    
	    }
	    bool ans=1;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            
	      bool flag= solve(adj,vis,i,col,0);
	      if(flag==0)
	      return 0;
	      
	        }
	    }
	    
	   return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
