//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// TC = O(E log E)
// SC = O(E) 

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	/*
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
    */
    
    // Kruskal Algorithm

    class Dis_joint_set {
    
        vector<int>rank;
        vector<int>parent;
        vector<int>size;
    
        public:
        Dis_joint_set(int n)
        {
            rank.resize(n+1 , 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0 ; i <= n ; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }
    
        int find_parent(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = find_parent(parent[node]);
        }
    
        void union_by_rank(int u , int v)
        {
            int ultimate_u = find_parent(u);
            int ultimate_v = find_parent(v);
    
            if(ultimate_u == ultimate_v)
                return;
            
            if(rank[ultimate_u] < rank[ultimate_v])
            {
                parent[ultimate_u] = ultimate_v;
            }
    
            else if(rank[ultimate_v] < rank[ultimate_u])
            {
                parent[ultimate_v] = ultimate_u;
            }
    
            else
            {
                parent[ultimate_v] = ultimate_u;
                rank[ultimate_u]++;
            }
        }
    
    
        void union_by_size(int u , int v)
        {
            int ultimate_u = find_parent(u);
            int ultimate_v = find_parent(v);
    
            if(ultimate_u == ultimate_v)
                return;
            
            if(size[ultimate_u] < size[ultimate_v])
            {
                parent[ultimate_u] = ultimate_v;
                size[ultimate_v] += size[ultimate_u];
            }
    
            else
            {
                parent[ultimate_v] = ultimate_u;
                size[ultimate_u] += size[ultimate_v];
            }
        }
    };
        
        // Minimum spanning tree using the kruskal algorithm and disjoint set
        int spanningTree(int V, vector<vector<int>> adj[])
        {
            vector<pair<int,pair<int,int>>> edges;
            for(int i = 0 ; i < V ; i++)
            {
                for(auto it : adj[i])
                {
                    int adj_node = it[0];
                    int wt = it[1];
                    int node = i;
                    
                    edges.push_back({wt , {node , adj_node}});
                }
            }
            
            Dis_joint_set ds(V);
            sort(edges.begin() , edges.end());
            int mst_wt = 0;
            
            for(auto it : edges)
            {
                int wt = it.first;
                int u = it.second.first;
                int v = it.second.second;
                
                
                if(ds.find_parent(u) != ds.find_parent(v))
                {
                    mst_wt += wt;
                    ds.union_by_size(u , v);
                }
            }
            
            return mst_wt;
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