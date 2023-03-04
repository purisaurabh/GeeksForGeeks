//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

long long int mod = 1e9+7;

class Solution {
  public:
    
    /*
    long long int nthFibonacci(long long int n)
    {
        long long int prev_1 = 1;
        long long int prev_2 = 0;
        
        for(int i = 2; i <= n ; i++)
        {
            long long int curr = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = curr;
        }
        
        return prev_1%mod;
        
    }
    */
    
    
    // The given appraoch is perfect but not optimise
    
    long long int find(long long int n , vector<long long int>&dp)
    {
        if(n <= 1)
            return n%mod;
            
        if(dp[n] != -1)
            return dp[n]%mod;
        
        dp[n] = find(n-1 , dp)%mod + find(n-2 , dp)%mod;
        return dp[n]%mod;
    }
    
    long long int nthFibonacci(long long int n)
    {
        // code here
        vector<long long int>dp(n+1 , -1);
        return find(n , dp);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends