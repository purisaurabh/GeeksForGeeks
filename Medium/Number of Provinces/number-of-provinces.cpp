//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution 
{

  public:
    void dfs(int node , vector<int> adj_list[] , int visited[])
    {
        visited[node] = 1;
        
        for(auto i : adj_list[node])
        {
            if(!visited[i])
            {
                dfs(i , adj_list , visited);
            }
        }
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        // code here
        
        // to change the adj matrix to adj list
        vector<int>adj_list[V];
        
        for(int i = 0; i < V ; i++)
        {
            for(int j = 0; j < V ; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        int visited[V] = {0};
        int count = 0;
        
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i , adj_list , visited);
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends