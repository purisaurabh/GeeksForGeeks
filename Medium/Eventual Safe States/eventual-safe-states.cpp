//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    /*
    // this is the appraoch using dfs 
  
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
    */
    
    
    
    // using thr topollogical sort or bfs
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        // first step is that we have to reverse the edge and vertex means we have to reverse the graph
        vector<int>adj_rev[V];
        vector<int>safe_node;
        
        int indegree[V] = {0};
        
        for(int i = 0 ; i < V ; i++)
        {
            for(auto it : adj[i])
            {
                adj_rev[it].push_back(i);
                indegree[i]++;
            }
        }

        
        queue<int>q;
        for(int i = 0 ; i < V ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            safe_node.push_back(node);
            
            for(auto it : adj_rev[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(safe_node.begin() , safe_node.end());
        return safe_node;
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