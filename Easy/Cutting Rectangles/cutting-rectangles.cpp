//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
       vector<long long int> v;

        long long int x= __gcd(L,B);

        v={(B/x)*(L/x),x};

          return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends