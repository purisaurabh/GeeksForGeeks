//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int n) 
    {
        // Code here
        long long ans = 0;
        if(n % 2)
        {
            n = n/2;
            ans = (long long)n*(n+1);
        }
        
        else
        {
            n = n/2;
            ans = (long long)n*n;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends