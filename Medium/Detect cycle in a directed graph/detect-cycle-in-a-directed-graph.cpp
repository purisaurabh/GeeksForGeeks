//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
        bool dfs(vector<int> adj[], int currNode, vector<bool> &visited , vector<bool> &dfs_visited)
        {
            visited[currNode] = true;
            dfs_visited[currNode] = true;
            
            for(int &v : adj[currNode])
            {
                if(visited[v] && dfs_visited[v])
                {
                    return true;
                }
                
                else if(!visited[v])
                {
                    if(dfs(adj, v, visited, dfs_visited)) 
                        return true;   
                }
            }
            
            dfs_visited[currNode] = false;
            return false;
        }
    
        bool isCyclic(int V, vector<int> adj[]) 
        {
            // code here
            vector<bool> visited(V, false), dfs_visited(V, false);
            
            for(int i=0; i<V; i++)
            {
                if(!visited[i])
                {
                    if(dfs(adj, i, visited, dfs_visited)) 
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