//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>>dist(n , vector<int>(n , INT_MAX));
        
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            dist[i][i] = 0;
        }
        
        for(int via = 0 ; via < n ; via++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    // if we are not reachable
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                        continue;
                    
                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int count_city = n;
        int city_number = -1;
        
        for(int city = 0; city < n ; city++)
        {
            int count = 0;
            for(int adj_city = 0 ; adj_city < n ; adj_city++)
            {
                if(dist[city][adj_city] <= distanceThreshold)
                {
                    count++;
                }
            }
            
            if(count <= count_city)
            {
                count_city = count;
                city_number = city;
            }
        }
        
        return city_number;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends