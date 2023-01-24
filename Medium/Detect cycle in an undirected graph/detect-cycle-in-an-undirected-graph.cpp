//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    /*
    
    Using DFS 
    
    private: 
    bool dfs(int node , int parent , int vis[], vector<int> adj[]) 
    {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) 
        {
            // unvisited adjacent node
            if(!vis[adjacentNode]) 
            {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            
            // visited node but not a parent node
            else if(adjacentNode != parent) 
                return true; 
        }
        return false; 
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
       int vis[V] = {0}; 
       
       // for graph with connected components 
       for(int i = 0 ; i < V ; i++) 
       {
           if(!vis[i]) 
           {
               if(dfs(i, -1, vis, adj) == true) 
                    return true; 
           }
       }
       return false; 
    }
    */
    \
    public:
    bool is_cycle(int start_node ,vector<int> adj[] , unordered_map<int,bool> &visited)
    {
        unordered_map<int , int>parent;
        parent[start_node] = -1;
        visited[start_node] = 1;
        queue<int>q;
        q.push(start_node);
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front])
            {
                if(visited[i] == 1 && i != parent[front])
                {
                    return true;    
                }
                
                else if(!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
                
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[])
    {
        unordered_map<int ,bool>visited;

        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                bool ans = is_cycle( i , adj , visited);
                
                if(ans == 1)
                    return true;
            }
        }
        
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