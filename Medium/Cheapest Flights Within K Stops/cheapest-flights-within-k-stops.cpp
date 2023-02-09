//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  
    {
        // Code here
        // first step create the graph
        vector<pair<int,int>>adj[n];
        for(auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v , wt});
        }
        // in the form of {stops , {node , cost}};
        queue<pair<int, pair<int,int>>> q;
        q.push({0 , {src , 0}});
        
        vector<int>dist(n , 1e9);
        dist[src] = 0;
        
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            
            // if we go beyond the stops no need go further
            if(stop > k)
                continue;
                
            // traverse the adj list
            for(auto i : adj[node])
            {
                int adj_node = i.first;
                int edge_wt = i.second;
                
                if(dist[adj_node] > cost + edge_wt && stop <= k)
                {
                    dist[adj_node] = cost + edge_wt;
                    q.push({stop+1 , {adj_node , cost+edge_wt}});
                }
            }
            
        }
        
        // if have not reached
        if(dist[dst] == 1e9)
            return -1;
            
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends