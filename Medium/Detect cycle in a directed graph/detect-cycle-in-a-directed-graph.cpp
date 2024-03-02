//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool iscyclic(vector<int> adj[], int src, vector<bool>& visited, vector<bool>& dfsvisited) {
    visited[src] = true;
    dfsvisited[src] = true;
    for (auto x : adj[src]) {
        if (!visited[x]) {
            if (iscyclic(adj, x, visited, dfsvisited))
                return true;
        } else if (visited[x] && dfsvisited[x]) {
            return true;
        }
    }
    dfsvisited[src] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> dfsvisited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (iscyclic(adj, i, visited, dfsvisited))
                return true;
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends