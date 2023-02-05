//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
        /*
        bool detectCycle(int node, int vis[], vector<int>adj[], int pathVis[]) 
        {
            vis[node] = 1;
            pathVis[node] = 1;
            
            for(auto i: adj[node]) 
            {
                if(!vis[i]) 
                {
                    if(detectCycle(i,vis,adj,pathVis) == true)
                        return true;
                }
                
                else if(pathVis[i] == 1)
                    return true;
            }
            
            pathVis[node] = 0;
            return false;
        }
         
        bool isCyclic(int V, vector<int> adj[]) 
        {
            int vis[V] = {0};
            int pathVis[V] = {0};
            
            for(int i = 0 ; i < V ; i++) 
            {
                if(!vis[i]) 
                {
                    if(detectCycle(i , vis , adj , pathVis))
                        return true;
                }
            }
            return false;
        }
        */
        
        
        
        
        
        // using the topological sort algorithm logic
        // in the topological sort algotrithm is valid for the directed acyclic graph 
        // which mean of cycle is not present then topologcal sort not gives the valid ans
        
        
        bool isCyclic(int V, vector<int> adj[]) 
        {
            int indegree[V] = {0};
        
            for(int i = 0; i < V ; i++)
            {
                for(auto &x : adj[i])
                {
                    indegree[x]++;
                }
            }
        
            queue<int>q;
            
            for(int i = 0 ; i < V ; i++)
            {
                if(indegree[i] == 0)
                    q.push(i);
            }
        
            int count = 0;
        
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
        
                count++;
        
                for(auto i : adj[front])
                {
                    indegree[i]--;
                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
        
            if(count == V)
                return false;
            
            return true;
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
        bool dfs(vector<int> adj[], int node, vector<bool> &visited , vector<bool> &dfs_visited)
        {
            visited[node] = true;
            dfs_visited[node] = true;
            
            for(int &v : adj[node])
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
            
            dfs_visited[node] = false;
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
        */
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