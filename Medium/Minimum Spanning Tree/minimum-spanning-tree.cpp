//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        
        // create the priority queue
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        // create the visited arr
        vector<int>visited(V , 0);
        
        // {wt , node}
        pq.push({0 , 0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            // if the node is already visited or already part of mst then do nothing
            if(visited[node] == 1)
                continue;
            
            // if not
            visited[node] = 1;
            sum += wt;
            
            for(auto it : adj[node])
            {
                int adj_node = it[0];
                int edge_wt = it[1];
                
                // if this is also not part of mst then push it into queue
                if(!visited[adj_node])
                {
                    pq.push({edge_wt , adj_node});
                }
            }
            
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends