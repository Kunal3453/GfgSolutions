//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
     bool dfs(vector<int> adj[], vector<bool>& vis, int source, int parent)
{
    // Mark the current node as visited
    vis[source] = true;
    
    // Iterate through all adjacent vertices of the current node
    for(auto u : adj[source])
    {
        // If the adjacent vertex is not visited, recursively call dfs
        if(vis[u] == false)
        {
            // Recursive call to dfs with the adjacent vertex
            // If dfs returns true, a cycle is detected, return true
            if(dfs(adj, vis, u, source))
            {
                return true;
            }
        }
        // If the adjacent vertex is already visited and not the parent of the current node,
        // it means there's a back edge indicating a cycle
        else if(u != parent)
        {
            return true;
        }
    }
    
    // If no cycle is detected in this connected component, return false
    return false;
}

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         // Initialize a boolean array to keep track of visited vertices
    vector<bool> vis(V, false);
    
    // Iterate through all vertices
    for(int i = 0; i < V; i++)
    {
        // If the current vertex is not visited, start dfs from it
        if(vis[i] == false)
        {
            // If dfs returns true, a cycle is detected, return true
            if(dfs(adj, vis, i, -1))
            {
                return true;
            }
        }
    }
    
    // If no cycle is detected in the entire graph, return false
    return false;

    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends