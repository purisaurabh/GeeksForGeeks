//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
        
    // using set
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>dist(V , 1e9);
        
        // like dist, node
        st.insert({0 , S});
        dist[S] = 0;
        
        while(!st.empty())
        {
            // in this st.begin() gives the address and * gives the value at that address
            auto it = *(st.begin());
            
            int node = it.second;
            int distance = it.first;
            
            st.erase(it);
            
            for(auto it : adj[node])
            {
                int adj_node = it[0];
                int edge = it[1];
                
                if(dist[adj_node] > dist[node] + edge)
                {
                    // check if the given adj node already exists or not
                    if(dist[adj_node] != 1e9)
                    {
                        st.erase({dist[node] , adj_node});
                    }
                    
                    dist[adj_node] = dist[node] + edge;
                    st.insert({dist[adj_node] , adj_node});
                } 
            }
        }
        
        return dist;
    }
    
    
    /*
    // using priority queue	
    // 	time complexity will be the  TC(E logV)
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int> > ,greater<pair<int,int>>> pq;
        vector<int>dist(V);
        for(int i = 0 ; i < V ; i++)
        {
            dist[i] = 1e9;
        }
        
        dist[S] = 0;
        
        pq.push({0 , S});
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int edge_weight = it[1];
                int adj_node = it[0];
                
                if(dist[adj_node] > edge_weight + dist[node])
                {
                    dist[adj_node] = edge_weight + dist[node];
                    pq.push({dist[adj_node] , adj_node});
                }
            }
        }
        
        return dist;
    }
    */
    
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends