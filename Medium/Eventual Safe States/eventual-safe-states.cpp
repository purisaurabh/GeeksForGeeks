//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    bool dfs(int node , vector<int>adj[] , int visited[] , int visited_path[] , int check[])
    {
        visited[node] = 1;
        visited_path[node] = 1;
        
        for(auto i : adj[node])
        {
            if(!visited[i])
            {
                if(dfs(i , adj , visited , visited_path , check) == true)
                    return true;
            }
            
            else if(visited_path[i])
            {
                return true;
            }
        }
        
        check[node] = 1;
        visited_path[node] = 0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        // code here
        int visited[V] = {0};
        int visited_path[V] = {0};
        int check[V] = {0};
        
        vector<int>safe_nodes;
        
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                dfs(i , adj , visited , visited_path , check);
            }
        }
        
        for(int i = 0 ; i < V; i++)
        {
            if(check[i] == 1)
            {
                safe_nodes.push_back(i);
            }
        }
        
        
        return safe_nodes;
        
        
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends