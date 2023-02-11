//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Dis_joint_set {

    public:
    
    vector<int>rank;
    vector<int>parent;
    vector<int>size;

    
    
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) 
    {
        // code here
        Dis_joint_set ds(n);
        
        int cnt_extras = 0;
        for(auto it :edge)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.find_parent(u) == ds.find_parent(v))
            {
                cnt_extras++;
            }
            
            else
            {
                ds.union_by_size(u , v);
            }
        }
        
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(ds.parent[i] == i)
                count++;
        }
        
        int ans = count - 1;
        if(cnt_extras >= ans)
        {
            return ans;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends