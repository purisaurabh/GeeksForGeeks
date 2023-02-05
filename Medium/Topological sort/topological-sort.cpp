//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(indegree[i] == 0) 
	            q.push(i);
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            
	            if(indegree[it] == 0) 
	                q.push(it);
	        }
	    }
	    return topo;
	}
	
	/*
	// by striver
	
	void dfs(int node , vector<int> adj[] , int visited[] , stack<int> &s)
	{
	    visited[node] = 1;
	    for(auto i : adj[node])
	    {
	        if(!visited[i])
	        {
	            dfs(i , adj , visited , s);
	        }
	    }
	    
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>v;
	    int visited[V] = {0};
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(!visited[i])
	        {
	            dfs(i , adj , visited , s);
	        }
	    }
	    
	    while(!s.empty())
	    {
	        v.push_back(s.top());
	        s.pop();
	    }
	    
	    return v;
	}
	
	*/
	
	
	
	
	
	
	
	
	
	
	/*
	
	// by babbar
	
	void dfs(int node , stack<int>&s , vector<bool>&visited , vector<int> adj[])
	{
	    visited[node] = 1;
	    for(auto i : adj[node])
	    {
	        if(!visited[i])
	        {
	            dfs(i , s , visited , adj);
	        }
	    }
	    
	    s.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>v;
	    vector<bool>visited(V , 0);
	    stack<int>s;
	    
	    for(int i = 0 ; i < V ; i++)
	    {
	        if(!visited[i])
	        {
	           dfs(i , s , visited , adj);
	        }
	    }
	    
	    
	    while(!s.empty())
	    {
	        v.push_back(s.top());
	        s.pop();
	    }
	    
	    return v;
	}
	
	*/
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends