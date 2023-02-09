//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        // code here
        
        //create the graph
        vector<pair<int,int>> adj[n];
        for(auto i : roads)
        {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt}); 
        }
        
        // create the priority queue store in the form of {dist , node}
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>>> pq;
        // create the dist arr which store the shortest distance
        vector<int>dist(n , 1e9);
        // create the ways arr which store the how many ways we can store at that particular node
        vector<int>way(n , 0); 
        
        dist[0] = 0;
        way[0] = 1;
        // {dist , node}
        pq.push({0 , 0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adj_node = it.first;
                int edge_wt = it.second;
                
                // this is the first time  i am coming with the short distance
                // carefully observed at the frist time we reached at the node
                if(dist[adj_node] > distance + edge_wt)
                {
                    dist[adj_node] = distance + edge_wt;
                    // for the first time
                    way[adj_node] = way[node];
                    pq.push({dist[adj_node] , adj_node});
                }
                
                else if(dist[adj_node] == distance + edge_wt)
                {
                    way[adj_node] = (way[adj_node] + way[node]) % mod; 
                }
            }
        }
        
        return way[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends