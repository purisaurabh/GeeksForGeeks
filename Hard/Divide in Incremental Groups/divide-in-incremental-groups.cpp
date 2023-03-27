//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    int dp[102][102][102];
    int solve(int i,int j,int k)
    {
        if(j==0 and k==0) return 1;
        if(j==0 and k!=0 or j!=0 and k==0) return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int ans=0;
        for(int l=i;l<=j;l++)
        {
            ans+=solve(l,j-l,k-1);
        }
        return dp[i][j][k]=ans;
    }
    int countWaystoDivide(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends