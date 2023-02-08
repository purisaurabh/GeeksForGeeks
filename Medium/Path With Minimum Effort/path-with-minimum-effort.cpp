//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) 
    {
        // Code here
        // {diff , {row , col}}
        priority_queue<pair<int,pair<int,int>> , 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        
        int n = heights.size();
        int m = heights[0].size();
        
        // distance vector store the shortest distance 
        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        
        // initially
        dist[0][0] = 0;
        pq.push({0 , {0 , 0}});
        
        int delrow[] = {-1 , 0 , +1 , 0};
        int delcol[] = {0 , +1 , 0 , -1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
        
            // here we get the answer
            if(row == n-1 && col == m-1)
                return diff;
            
            
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m )
                {
                    int new_efforts = max(abs(heights[row][col] - heights[nrow][ncol]) , diff);
                    if(new_efforts < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = new_efforts;
                        pq.push({new_efforts , {nrow , ncol}});
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends