//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        int ans=INT_MIN;
        int dp[n][n];
        for(int i=0; i<n; i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0)    dp[i][j]=matrix[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
                else if(j==n-1) dp[i][j]=matrix[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
                else    dp[i][j]=matrix[i][j]+max({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
            }
        }
        for(int i=0; i<n; i++)
        {
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends