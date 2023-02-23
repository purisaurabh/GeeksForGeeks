//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) 
    {
        // code here
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        if(grid[0][0]==0 || grid[n-1][m-1]==0) 
            return 0;
        dp[n-1][m-1] = 1;
        
        for(int i = n-1;i>=0;i--)
        {
            for(int j =m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) 
                    continue;
                    
                if(grid[i][j]==1)
                {
                    dp[i][j] = (dp[i+1][j] + dp[i][j+1])%mod;
                }
            }
        }
        return dp[0][0];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends