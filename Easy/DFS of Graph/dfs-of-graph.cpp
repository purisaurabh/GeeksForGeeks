//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    void dfs(int start_node , vector<int>adj[] , int visited[] , vector<int>&ans)
    {
        visited[start_node] = 1;
        ans.push_back(start_node);
        
        for(auto i : adj[start_node])
        {
            if(!visited[i])
            {
                dfs(i , adj , visited  , ans);
            }
        }
        
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        
        //  make a visited array for the store the visited element;
        int visited[V] = {0};
        
        // starting node
        int start_node = 0;
        
        vector<int>ans;
        
        dfs(start_node , adj , visited , ans);
        
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends