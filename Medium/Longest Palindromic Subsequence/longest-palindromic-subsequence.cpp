//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int find_value(string &a , string &b , int i , int j , vector<vector<int>> &dp)
    {
        if(i == a.size() || j == b.size()) 
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        // if match
        if(a[i] == b[j])
            ans = 1 + find_value(a , b , i+1 , j+1 , dp);
        
        else
            ans = max(find_value (a , b , i+1 , j , dp) , find_value(a , b , i , j+1 , dp));
        
        return dp[i][j] = ans;
    }
    
    int longestPalinSubseq(string str) {
        string rev_str = str;
        reverse(rev_str.begin() , rev_str.end());
        vector<vector<int>>dp(str.size() , vector<int>(rev_str.size() , -1));
        return find_value(str , rev_str , 0 , 0 , dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends