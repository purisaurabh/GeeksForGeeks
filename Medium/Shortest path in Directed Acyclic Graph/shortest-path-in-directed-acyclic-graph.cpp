//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void dfs(int node , vector<pair<int,int>> adj[] , int visited[] , stack<int>&st)
    {
        visited[node] = 1;
        for(auto i : adj[node])
        {
            int v = i.first;
            if(!visited[v])
            {
                dfs(v , adj , visited , st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        // code here
        vector<pair<int,int>>adj[N];
        
        for(int i = 0 ; i < M ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v , wt});
        }
        
        int visited[N] = {0};
        
        // get the topological sort
        stack<int>st;
        for(int i = 0 ; i < N ; i++)
        {
            if(!visited[i])
            {
                dfs(i , adj , visited , st);
            }
        }
        
        
        // update the distance array from 
        vector<int>dist(N);
        for(int i = 0 ; i < N ; i++)
        {
            dist[i] = 1e9;
        }
        
        // if source vertex is not given then consider as 0 if make dist[source] = 0
        dist[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto i : adj[node])
            {
                int v = i.first;
                int wt = i.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
            
        }
        
        for(int i = 0 ; i < dist.size(); i++)
        {
            if(dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        
        
        return dist;
    }
    
    
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends