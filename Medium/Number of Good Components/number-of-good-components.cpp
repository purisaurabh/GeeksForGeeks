//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int dfs(int node , vector<int>&visited , vector<vector<int>>& adj , int &no_of_nodes)
    {
        visited[node] = 1;
        int size = 1;
        for(auto i : adj[node])
        {
            no_of_nodes++;
            if(!visited[i])
            {
                size += dfs(i , visited , adj , no_of_nodes);
            }
        }
        
        return size;
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) 
    {
        // code here
        vector<int>visited(V+1, 0);
        
        int ans = 0;
        for(int i =1 ; i <= V ; i++)
        {
            int size = 0;
            int no_of_nodes = 0;
            if(!visited[i])
            {
                size = dfs(i , visited , adj , no_of_nodes);
                int total_size = size*(size-1);
                
                if(total_size == no_of_nodes)
                    ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends