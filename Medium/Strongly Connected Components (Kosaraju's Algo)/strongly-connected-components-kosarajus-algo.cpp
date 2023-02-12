//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	    
	void dfs3(int node , vector<int>&visited , vector<int>adjT[])
	{
	    visited[node] = 1;
	    for(auto i : adjT[node])
	    {
	        if(!visited[i])
	        {
	            dfs3(i , visited , adjT);
	        }
	    }
	}
	
	// this is for the step 1
	void dfs(int node , vector<int>&visited , vector<int>adj[] , stack<int>&st)
	{
	    visited[node] = 1;
	    for(auto i : adj[node])
	    {
	        if(!visited[i])
	        {
	            dfs(i , visited , adj , st);
	        }
	    }
	    
	    st.push(node);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>visited(V , 0);
        stack<int>st;
        
        // step 1
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                dfs(i , visited , adj , st);
            }
        }
        
        // step 2 reverse the graph
        vector<int>adjT[V];
        for(int i = 0 ; i < V; i++)
        {
            // we marked as unvisited because we can use them again
            visited[i] = 0;
            for(auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        int scc = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if(!visited[node])
            {
                scc++;
                dfs3(node , visited , adjT);
            }
        }
        
        return scc;
        
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends