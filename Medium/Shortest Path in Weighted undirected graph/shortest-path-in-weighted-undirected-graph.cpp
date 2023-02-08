//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        
        // create the adj list
        vector<pair<int,int>> adj[n+1];
        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        
        //create the priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // create the parent arr
        vector<int>parent(n+1);
        //create the dist arr
        vector<int>dist(n+1 , 1e9);
        
        for(int i = 1; i <= n ; i++)
        {
            parent[i] = i;
        }
        
        //      dist , node
        pq.push({0 , 1});
        dist[1] = 0;
        
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            
            int u = p.second;
            int d = p.first;
            
            for(auto i : adj[u])
            {
                int v = i.first;
                int wt = i.second;
                
                if(dist[v] > d + wt)
                {
                    dist[v] = d + wt;
                    parent[v] = u;
                    pq.push({dist[v] , v});
                }
            }
        }
        
        if(dist[n] == 1e9)
        {
            return {-1};
        }
        
        vector<int>path;
        while(parent[n] != n)
        {
            path.push_back(n);
            n = parent[n];
        }
        
        path.push_back(1);
        reverse(path.begin() , path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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