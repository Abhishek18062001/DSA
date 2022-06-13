#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   bool dfs(vector<int> adj[], int curr, bool visited[] ,int parent)
    {
        visited[curr] = true;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            int child=adj[curr][i];
            if(visited[child] == false)
            {
                if(dfs(adj, child, visited, curr) == true)
                    return true;
            }
            else if(child != parent)
                return true;
        }
        
        return false;
    }
   bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
            
        for(int i = 0; i < V; i++)
        {
            
            if(visited[i] == false)
            {
                if(dfs(adj, i, visited, -1) == true)
                return true;
            }
            
        }
        
        return false;
        }
    
    
   
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
