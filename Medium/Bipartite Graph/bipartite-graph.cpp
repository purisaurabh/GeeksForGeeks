//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

private:
    bool dfs(int node , int colour , int color[] , vector<int>adj[])
    {
        color[node] = colour;
        for(auto i : adj[node])
        {
            if(color[i] == -1)
            {
                if(dfs(i , !colour , color , adj) == false)
                    return false;
            }
            
            else if(color[i] == color[node])
                return false;
        }
        
        return true;
    }
    
public:
    bool isBipartite(int V, vector<int>adj[])
    {
        int color[V];
        for(int i = 0 ; i < V; i++)
        {
            color[i] = -1;
        }
        
        int colour = 0;
        for(int i = 0 ; i < V; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i , colour , color , adj) == false)
                    return false;
            }
        }
        
        return true;
    }
    
    
    /*
    bool check_bipartite(int start_node , int V , vector<int>adj[] , int color[])
    {
        queue<int>q;
	    q.push(start_node);
	    
	    // first node colored with 0
	    color[start_node] = 0;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto i : adj[node])
	        {
	            // if the adjacent node is yet not colored
	            // you will give the opposite color of the node
	            if(color[i]== -1)
	            {
	                color[i] = !color[node];
	                q.push(i);
	            }
	            
	            // is the adjacent guy having the same color
	            else if(color[i] == color[node])
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }
    
    
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Code here
	    int color[V];
	    for(int i = 0 ; i < V ; i++)
	    {
	        color[i] = -1;
	    }
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(check_bipartite(i , V , adj , color) == false)
	                return false;
	        }
	    }
	    
	    return true;
	}
	*/

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends